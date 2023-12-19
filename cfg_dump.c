/* cfg_dump.c - Example code dumping UM objects' configuration. */
/*
  Copyright (c) 2022-2023 Informatica Corporation
  Permission is granted to licensees to use or alter this software for any
  purpose, including commercial applications, according to the terms laid
  out in the Software License Agreement.

  This source code example is provided by Informatica for educational
  and evaluation purposes only.

  THE SOFTWARE IS PROVIDED "AS IS" AND INFORMATICA DISCLAIMS ALL WARRANTIES 
  EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY IMPLIED WARRANTIES OF 
  NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR 
  PURPOSE.  INFORMATICA DOES NOT WARRANT THAT USE OF THE SOFTWARE WILL BE 
  UNINTERRUPTED OR ERROR-FREE.  INFORMATICA SHALL NOT, UNDER ANY CIRCUMSTANCES,
  BE LIABLE TO LICENSEE FOR LOST PROFITS, CONSEQUENTIAL, INCIDENTAL, SPECIAL OR 
  INDIRECT DAMAGES ARISING OUT OF OR RELATED TO THIS AGREEMENT OR THE 
  TRANSACTIONS CONTEMPLATED HEREUNDER, EVEN IF INFORMATICA HAS BEEN APPRISED OF 
  THE LIKELIHOOD OF SUCH DAMAGES.
*/

#include <stdio.h>
#include <string.h>
#if ! defined(_WIN32)
  #include <stdlib.h>
  #include <unistd.h>
#endif

#include "lbm/lbm.h"

/* Simple error handler. */
#define E(lbm_funct_call_) do { \
  int e_ = (lbm_funct_call_); \
  if (e_ == LBM_FAILURE) { \
    fprintf(stderr, "ERROR (%s:%d): %s failed: '%s'\n", \
       __FILE__, __LINE__, #lbm_funct_call_, lbm_errmsg()); \
    fflush(stderr); \
    exit(1); \
  } \
} while (0)  /* E */


/* UM callback for receiver events, including received messages. */
int my_rcv_cb(lbm_rcv_t *rcv, lbm_msg_t *msg, void *clientd)
{
  return 0;
}


void print_opts(lbm_config_option_t *rcv_opts, int num_opts, char *header)
{
  int i;

  printf("%s\n", header);
  for (i = 0; i < num_opts; i++) {
    printf("  %s %s %s\n", rcv_opts[i].type, rcv_opts[i].oname, rcv_opts[i].val);
  }
}  /* print_opts */


void print_context(lbm_context_t *ctx, char *header)
{
  int err;
  int num_opts = lbm_context_attr_option_size();
  lbm_config_option_t *opts = (lbm_config_option_t *)malloc(sizeof(lbm_config_option_t) * num_opts);

  err = lbm_context_dump(ctx, &num_opts, opts);  E(err);
  print_opts(opts, num_opts, header);
  free(opts);
}  /* print_context */


void print_rcv(lbm_rcv_t *rcv, char *header)
{
  int err;
  int num_opts = lbm_rcv_topic_attr_option_size();
  lbm_config_option_t *opts = (lbm_config_option_t *)malloc(sizeof(lbm_config_option_t) * num_opts);

  err = lbm_rcv_topic_dump(rcv, &num_opts, opts);  E(err);
  print_opts(opts, num_opts, header);
  free(opts);
}  /* print_rcv */


void print_src(lbm_src_t *src, char *header)
{
  int err;
  int num_opts = lbm_src_topic_attr_option_size();
  lbm_config_option_t *opts = (lbm_config_option_t *)malloc(sizeof(lbm_config_option_t) * num_opts);

  err = lbm_src_topic_dump(src, &num_opts, opts);  E(err);
  print_opts(opts, num_opts, header);
  free(opts);
}  /* print_src */


void print_ssrc(lbm_ssrc_t *ssrc, char *header)
{
  int err;
  int num_opts = lbm_src_topic_attr_option_size();  /* Smart src uses the regular "src" API. */
  lbm_config_option_t *opts = (lbm_config_option_t *)malloc(sizeof(lbm_config_option_t) * num_opts);

  err = lbm_ssrc_topic_dump(ssrc, &num_opts, opts);  E(err);
  print_opts(opts, num_opts, header);
  free(opts);
}  /* print_ssrc */


int main(int argc, char **argv)
{
  int err;
  lbm_context_t *my_ctx;
  lbm_topic_t *topic_obj;
  lbm_rcv_t *my_rcv;
  lbm_src_t *my_src;
  lbm_ssrc_t *my_ssrc;

  err = lbm_config("cfg_dump.cfg");  E(err);

  err = lbm_context_create(&my_ctx, NULL, NULL, NULL);  E(err);
  print_context(my_ctx, "Context");

  err = lbm_rcv_topic_lookup(&topic_obj, my_ctx, "MyTopic", NULL);  E(err);
  err = lbm_rcv_create(&my_rcv, my_ctx, topic_obj, my_rcv_cb, NULL, NULL);  E(err);
  print_rcv(my_rcv, "Receiver MyTopic");

  err = lbm_src_topic_alloc(&topic_obj, my_ctx, "MyTopic", NULL);  E(err);
  err = lbm_src_create(&my_src, my_ctx, topic_obj, NULL, NULL, NULL);  E(err);
  print_src(my_src, "Source MyTopic");

  err = lbm_src_topic_alloc(&topic_obj, my_ctx, "MySmartTopic", NULL);  E(err);
  err = lbm_ssrc_create(&my_ssrc, my_ctx, topic_obj, NULL,  NULL, NULL);  E(err);
  print_ssrc(my_ssrc, "SmartSource MySmartTopic");
}  /* main */
