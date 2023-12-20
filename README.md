# cfg_dump

Example code dumping UM objects' configuration

# Table of contents

<!-- mdtoc-start -->
&bull; [cfg_dump](#cfg_dump)  
&bull; [Table of contents](#table-of-contents)  
&bull; [Copyright And License](#copyright-and-license)  
&bull; [Repository](#repository)  
&bull; [Introduction](#introduction)  
&bull; [Coding Notes](#coding-notes)  
&nbsp;&nbsp;&nbsp;&nbsp;&bull; [C Error Handling](#c-error-handling)  
&bull; [Sample output](#sample-output)  
<!-- TOC created by '/home/sford/bin/mdtoc.pl README.md' (see https://github.com/fordsfords/mdtoc) -->
<!-- mdtoc-end -->

# Copyright And License

All of the documentation and software included in this and any
other Informatica Ultra Messaging GitHub repository
Copyright (C) Informatica, 2022. All rights reserved.

Permission is granted to licensees to use
or alter this software for any purpose, including commercial applications,
according to the terms laid out in the Software License Agreement.

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

# Repository

See https://github.com/UltraMessaging/cfg_dump for code and documentation.

# Introduction

UM provides multiple methods of configuring UM objects.
It is not unusual for applications to use a combination of
code-based APIs, flat files, and XML files.
It can be tedious and error-prone to determine via static analysis
exactly how UM objects will be configured.
Some UM users have opted to write their applications to
log their UM objects' configurations after the objects are
created, thus leaving no room for error.

This repository contains example C and Java programs to demonstrate dumping
(printing) the configurations of a UM context,
receiver, smart source, and regular source objects.
The dumps are simple ascii text and are written to standard output.

* cfg_dump.c - demo C program that performs the configuration dumping.
* CfgDump.java - demo Java program that performs the configuration dumping.
* bld.sh - shell script to build the demo programs.
* tst.sh - shell script to run the demo programs.

Both scripts expect a file "lbm.sh" that sets up your UM environment. See "lbm.sh.example" as a model.

There are a few other object types that are not demonstrated,
like event queues and hot failover receivers.
Those should be straightforward to code given these examples.

# Coding Notes

The configuration dumping APIs take a UM object that has been created and
prints the configured attributes.

C example:
````
print_context(my_ctx, "Context");
````
Java example:
````
printContext(myCtx, "Context");
````
A real program would modify these functions functions to
send the configuration information to the log file
using the established logging infrastructure.

## C Error Handling

To make the code easier to follow, a very simple error handling convention is used.
The code macro "E()" is invoked for each UM API.
The macro checks the return code for error, prints the details to stndard error and exits with status of 1.

For example:
````
E(lbm_config("cfg_dump.cfg"));
````
Demonstrate an error:
````
$ ./bld.sh
$ mv cfg_dump.cfg cfg_dump.sav
$ ./tst.sh
ERROR (cfg_dump.c:111): lbm_config("cfg_dump.cfg") failed: 'CoreApi-5688-62: could not open config file'
$ mv cfg_dump.sav cfg_dump.cfg
````

# Sample output

This is with UM version 6.14.

````
$ ./bld.sh
$ ./tst.sh
cfg_dump
Core-10403-150: Context (0x56499dd3b810) created with ContextID (2138964188) and ContextName [(NULL)]
Context
  context operational_mode embedded
  context fd_management_type select
  context broker 
  context resolver_service 
  context resolver_service_interest_mode filter
  context resolver_multicast_address 224.9.10.11
  context resolver_multicast_outgoing_address 224.9.10.11
  context resolver_multicast_incoming_address 224.9.10.11
  context resolver_multicast_port 12965
  context resolver_multicast_outgoing_port 12965
  context resolver_multicast_incoming_port 12965
  context resolver_multicast_ttl 16
  context resolver_multicast_interface 192.168.158.34
  context resolver_initial_advertisements_per_second 1000
  context resolver_initial_advertisement_bps 1000000
  context resolver_sustain_advertisements_per_second 0
  context resolver_sustain_advertisement_bps 1000000
  context resolver_initial_queries_per_second 1000
  context resolver_initial_query_bps 1000000
  context resolver_sustain_queries_per_second 0
  context resolver_sustain_query_bps 1000000
  context resolver_wildcard_queries_per_second 0
  context resolver_wildcard_query_bps 1000000
  context resolver_multicast_receiver_socket_buffer 8388608
  context resolver_disable_udp_topic_resolution 0
  context transport_tcp_port_high 14390
  context transport_tcp_port_low 14371
  context transport_tcp_maximum_ports 10
  context transport_tcp_receiver_socket_buffer 0
  context request_tcp_bind_request_port 1
  context request_tcp_interface 0.0.0.0
  context request_tcp_port 14391
  context request_tcp_port_high 14395
  context request_tcp_port_low 14391
  context request_tcp_listen_backlog 5
  context request_tcp_reuseaddr 0
  context request_tcp_exclusiveaddr 1
  context response_tcp_nodelay 0
  context response_tcp_deletion_timeout 20000
  context response_session_maximum_buffer 65536
  context response_session_sender_socket_buffer 0
  context response_tcp_interface 0.0.0.0
  context transport_lbtrm_multicast_address_high 224.10.10.14
  context transport_lbtrm_multicast_address_low 224.10.10.10
  context transport_lbtrm_data_rate_limit 10000000
  context transport_lbtrm_rate_interval 10
  context transport_lbtrm_retransmit_rate_limit 5000000
  context transport_lbtrm_receiver_socket_buffer 8388608
  context transport_lbtrm_source_socket_buffer 1048576
  context transport_lbtrm_source_port_high 14399
  context transport_lbtrm_source_port_low 14390
  context delivery_control_maximum_total_map_entries 200000
  context transport_lbtrm_receiver_timestamp 0
  context transport_lbtrm_source_timestamp 0
  context mim_address 0.0.0.0
  context mim_outgoing_address 224.10.10.21
  context mim_incoming_address 0.0.0.0
  context mim_destination_port 14401
  context mim_outgoing_destination_port 14401
  context mim_incoming_destination_port 14401
  context mim_nak_backoff_interval 200
  context mim_nak_initial_backoff_interval 50
  context mim_nak_suppress_interval 1000
  context mim_nak_generation_interval 10000
  context mim_activity_timeout 60000
  context mim_send_naks 1
  context mim_tgsz 8
  context mim_ignore_interval 500
  context mim_sm_minimum_interval 200
  context mim_sm_maximum_interval 10000
  context mim_src_deletion_timeout 30000
  context mim_transmission_window_size 25165824
  context mim_transmission_window_limit 0
  context mim_implicit_batching_minimum_length 2048
  context mim_implicit_batching_interval 200
  context mim_delivery_control_order_tablesz 1031
  context mim_ordered_delivery 1
  context mim_delivery_control_activity_timeout 60000
  context mim_delivery_control_activity_check_interval 5000
  context resolver_unicast_address 0.0.0.0
  context resolver_unicast_interface 0.0.0.0
  context resolver_unicast_port 0
  context resolver_unicast_port_high 14406
  context resolver_unicast_port_low 14402
  context resolver_unicast_destination_port 15380
  context resolver_unicast_receiver_socket_buffer 8388608
  context resolver_unicast_force_alive 0
  context resolver_source_map_tablesz 131111
  context resolver_receiver_map_tablesz 131111
  context resolver_wildcard_receiver_map_tablesz 10273
  context resolver_string_hash_function murmur2
  context resolver_cache 1
  context transport_lbtru_data_rate_limit 10000000
  context transport_lbtru_rate_interval 100
  context transport_lbtru_retransmit_rate_limit 5000000
  context transport_lbtru_receiver_socket_buffer 8388608
  context transport_lbtru_source_socket_buffer 1048576
  context transport_lbtru_port_high 14389
  context transport_lbtru_port_low 14380
  context transport_lbtru_maximum_ports 5
  context transport_lbtipc_id_high 20005
  context transport_lbtipc_id_low 20001
  context transport_lbtipc_receiver_thread_behavior pend
  context transport_lbtipc_pend_behavior_linger_loop_count 1
  context transport_lbtipc_receiver_operational_mode embedded
  context transport_lbtsmx_id_high 30005
  context transport_lbtsmx_id_low 30001
  context transport_lbtsmx_receiver_operational_mode embedded
  context transport_lbtsmx_message_statistics_enabled 0
  context transport_lbtrdma_port_high 20020
  context transport_lbtrdma_port_low 20001
  context transport_lbtrdma_maximum_ports 5
  context transport_lbtrdma_receiver_thread_behavior pend
  context transport_session_multiple_sending_threads 1
  context receive_thread_pool_size 4
  context receive_thread_pool_behavior create_only
  context ume_user_receiver_registration_id 00000000
  context monitor_interval 0
  context monitor_transport lbm
  context monitor_transport_opts 
  context monitor_appid 
  context monitor_format csv
  context monitor_format_opts 
  context transport_tcp_datagram_max_size 65535
  context transport_lbtrm_datagram_max_size 8192
  context transport_lbtru_datagram_max_size 8192
  context transport_lbtipc_datagram_max_size 65535
  context transport_lbtrdma_datagram_max_size 4096
  context resolver_datagram_max_size 8192
  context source_includes_topic_index 1
  context dbl_lbtru_acceleration 0
  context dbl_lbtrm_acceleration 0
  context dbl_resolver_acceleration 0
  context dbl_mim_acceleration 0
  context ud_acceleration 0
  context disable_extended_topic_resolution_message_options 0
  context timestamp_mask 0x0
  context delivery_latency_sampling 0
  context ume_session_id 0x0
  context umq_session_id 0x0
  context network_compatibility_mode default
  context dynamic_fragmentation_reduction 0
  context compatibility_include_pre_um_6_0_behavior 0
  context compatibility_pre_um_6_0_context_ad_interval 0
  context context_name 
  context ume_ack_batching_interval 100
  context mim_delivery_control_loss_check_interval 0
  context resolver_unicast_activity_timeout 1000
  context resolver_unicast_keepalive_interval 500
  context resolver_unicast_change_interval 500
  context resolver_unicast_check_interval 200
  context resolver_unicast_daemon 
  context application_data 
  context mim_sqn_window_size 16384
  context mim_sqn_window_increment 8192
  context ume_liveness_detection_table_size 131
  context ume_receiver_liveness_interval 0
  context ume_source_liveness_timeout 0
  context resolver_ud_acceleration 0
  context resolver_context_name_query_minimum_interval 100
  context resolver_context_name_query_maximum_interval 1000
  context resolver_context_name_query_duration 0
  context resolver_context_name_activity_timeout 10000
  context delivery_control_message_batching 0
  context tls_cipher_suites TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
  context ume_proactive_keepalive_interval 3000
  context tls_certificate 
  context tls_certificate_key 
  context tls_certificate_key_password 
  context tls_trusted_certificates system
  context use_tls 0
  context compression none
  context tls_compression_negotiation_timeout 5000
  context resolver_unicast_ignore_unknown_source 1
  context resolver_domain_id_active_propagation_timeout 0
  context multiple_receive_maximum_datagrams 0
  context default_interface 0.0.0.0
  context transport_lbtrm_recycle_receive_buffers 0
  context transport_lbtru_recycle_receive_buffers 0
  context transport_lbtipc_recycle_receive_buffers 0
  context transport_session_single_receiving_thread 0
  context file_descriptor_management_behavior pend
  context round_robin_xsp_count 0
Receiver MyTopic
  receiver transport_lbtrm_nak_backoff_interval 200
  receiver transport_lbtrm_nak_initial_backoff_interval 50
  receiver transport_lbtrm_nak_suppress_interval 1000
  receiver transport_lbtrm_nak_generation_interval 10000
  receiver transport_lbtrm_preactivity_timeout 0
  receiver transport_lbtrm_activity_timeout 60000
  receiver transport_lbtrm_send_naks 1
  receiver transport_tcp_interface 0.0.0.0
  receiver transport_tcp_activity_timeout 0
  receiver transport_tcp_activity_method timer
  receiver transport_tcp_dro_loss_recovery_timeout 0
  receiver delivery_control_loss_tablesz 131
  receiver delivery_control_order_tablesz 131
  receiver delivery_control_maximum_burst_loss 1024
  receiver delivery_control_loss_check_interval 0
  receiver resolution_no_source_notification_threshold 0
  receiver resolution_number_of_sources_query_threshold 10000000
  receiver resolver_query_minimum_initial_interval 20
  receiver resolver_query_maximum_initial_interval 200
  receiver resolver_query_minimum_initial_duration 5000
  receiver resolver_query_sustain_interval 1000
  receiver resolver_query_minimum_sustain_duration 60
  receiver ordered_delivery 1
  receiver transport_lbtru_nak_backoff_interval 200
  receiver transport_lbtru_nak_initial_backoff_interval 0
  receiver transport_lbtru_nak_suppress_interval 1000
  receiver transport_lbtru_nak_generation_interval 10000
  receiver transport_lbtru_activity_timeout 60000
  receiver transport_lbtru_connect_interval 100
  receiver transport_lbtru_acknowledgement_interval 500
  receiver transport_lbtru_interface 0.0.0.0
  receiver transport_lbtru_port_high 14379
  receiver transport_lbtru_port_low 14360
  receiver transport_lbtru_maximum_connect_attempts 600
  receiver transport_lbtipc_activity_timeout 60000
  receiver transport_lbtipc_dro_loss_recovery_timeout 0
  receiver transport_lbtsmx_activity_timeout 60000
  receiver ume_use_store 1
  receiver ume_use_late_join 1
  receiver use_late_join 1
  receiver ume_retransmit_request_interval 500
  receiver retransmit_request_interval 500
  receiver ume_retransmit_request_generation_interval 
  receiver retransmit_request_generation_interval 
  receiver retransmit_request_message_timeout 10000
  receiver ume_retransmit_request_maximum 0
  receiver retransmit_request_maximum 0
  receiver ume_registration_interval 3000
  receiver ume_retransmit_request_outstanding_maximum 10
  receiver retransmit_request_outstanding_maximum 10
  receiver retransmit_message_caching_proximity 5000
  receiver ume_explicit_ack_only 0
  receiver ume_consensus_sequence_number_behavior majority
  receiver hf_duplicate_delivery 0
  receiver hf_optional_messages 1
  receiver umq_hold_limit 0
  receiver umq_queue_participation 0
  receiver unrecognized_channel_behavior deliver
  receiver null_channel_behavior deliver
  receiver channel_map_tablesz 10273
  receiver use_transport_thread 0
  receiver transport_demux_tablesz 1
  receiver ume_state_lifetime 0
  receiver ume_activity_timeout 0
  receiver ume_session_id 0x0
  receiver retransmit_initial_sequence_number_request 1
  receiver ume_use_ack_batching 1
  receiver rcv_sync_cache 
  receiver rcv_sync_cache_timeout 5000
  receiver application_data 
  receiver ume_allow_confirmed_delivery 1
  receiver use_otr 2
  receiver otr_request_minimum_interval 1000
  receiver otr_request_maximum_interval 10000
  receiver otr_request_duration 
  receiver otr_request_initial_delay 2000
  receiver otr_request_outstanding_maximum 200
  receiver otr_request_log_alert_cooldown 300
  receiver otr_message_caching_threshold 10000
  receiver otr_request_message_timeout 60000
  receiver ume_receiver_paced_persistence 0
  receiver message_selector 
  receiver ume_sri_request_interval 1000
  receiver ume_sri_request_maximum 60
  receiver transport_topic_sequence_number_info_request_interval 1000
  receiver transport_topic_sequence_number_info_request_maximum 60
  receiver late_join_info_request_interval 1000
  receiver late_join_info_request_maximum 60
  receiver monitor_interval 0
  receiver onload_acceleration_stack_name 
  receiver ume_application_outstanding_maximum 0
  receiver ume_recovery_complete_event 0
Source MyTopic
  source transport LBT-RM
  source resolver_ttl 60
  source resolver_send_initial_advertisement 1
  source resolver_send_final_advertisements 0
  source resolver_advertisement_minimum_initial_interval 10
  source resolver_advertisement_maximum_initial_interval 500
  source resolver_advertisement_minimum_initial_duration 5000
  source resolver_advertisement_sustain_interval 1000
  source resolver_advertisement_minimum_sustain_duration 60
  source resolver_advertisement_send_immediate_response 1
  source transport_tcp_port 0
  source transport_tcp_interface 0.0.0.0
  source transport_tcp_reuseaddr 0
  source transport_tcp_exclusiveaddr 1
  source transport_tcp_nodelay 1
  source transport_tcp_sender_socket_buffer 0
  source transport_tcp_listen_backlog 5
  source transport_tcp_activity_timeout 0
  source transport_tcp_multiple_receiver_behavior normal
  source transport_tcp_multiple_receiver_send_order serial
  source transport_tcp_coalesce_threshold 1024
  source transport_tcp_use_session_id 1
  source transport_source_side_filtering_behavior none
  source transport_session_maximum_buffer 65536
  source transport_lbtrm_multicast_address 224.10.10.10
  source transport_lbtrm_tgsz 8
  source transport_lbtrm_destination_port 14400
  source transport_lbtrm_ignore_interval 500
  source transport_lbtrm_sm_minimum_interval 200
  source transport_lbtrm_sm_maximum_interval 10000
  source transport_lbtrm_transmission_window_size 25165824
  source transport_lbtrm_transmission_window_limit 0
  source transport_lbtrm_coalesce_threshold 15
  source smart_src_max_message_length 368
  source smart_src_user_buffer_count 32
  source smart_src_retention_buffer_count 1024
  source smart_src_enable_spectrum_channel 0
  source smart_src_enable_transport_compatibility 1
  source smart_src_message_property_int_count 0
  source transport_lbtrm_smart_src_transmission_window_buffer_count 16384
  source transport_lbtru_smart_src_transmission_window_buffer_count 16384
  source implicit_batching_minimum_length 2048
  source implicit_batching_interval 200
  source implicit_batching_type default
  source transport_topic_sequence_number_info_interval 5000
  source transport_topic_sequence_number_info_active_threshold 60
  source transport_lbtru_transmission_window_size 25165824
  source transport_lbtru_transmission_window_limit 0
  source transport_lbtru_client_map_size 7
  source transport_lbtru_ignore_interval 500
  source transport_lbtru_sm_minimum_interval 200
  source transport_lbtru_sm_maximum_interval 10000
  source transport_lbtru_client_activity_timeout 10000
  source transport_lbtru_port 0
  source transport_lbtru_interface 0.0.0.0
  source transport_lbtru_coalesce_threshold 15
  source transport_lbtru_use_session_id 1
  source transport_lbtipc_transmission_window_size 25165824
  source transport_lbtipc_behavior source_paced
  source transport_lbtipc_maximum_receivers_per_transport 20
  source transport_lbtipc_id 0
  source transport_lbtipc_sm_interval 10000
  source transport_lbtsmx_transmission_window_size 131072
  source transport_lbtsmx_datagram_max_size 8192
  source transport_lbtsmx_maximum_receivers_per_transport 64
  source transport_lbtsmx_id 0
  source transport_lbtsmx_sm_interval 10000
  source transport_lbtrdma_port 0
  source transport_lbtrdma_interface 0.0.0.0
  source transport_lbtrdma_transmission_window_size 25165824
  source ume_late_join 0
  source late_join 0
  source ume_confirmed_delivery_notification 0
  source ume_message_stability_notification 1
  source ume_quasar_flight_size_behavior 0
  source ume_flight_size 1000
  source ume_flight_size_bytes 0
  source ume_flight_size_behavior block
  source ume_retention_size_threshold 0
  source retransmit_retention_size_threshold 0
  source ume_retention_size_limit 25165824
  source retransmit_retention_size_limit 25165824
  source ume_retention_unique_confirmations 0
  source ume_registration_interval 3000
  source ume_message_map_tablesz 0
  source retransmit_message_map_tablesz 0
  source ume_store_check_interval 500
  source ume_store_activity_timeout 10000
  source ume_store 
  source ume_store_group 
  source ume_store_behavior quorum-consensus
  source ume_retention_intergroup_stability_behavior any-group
  source ume_retention_intragroup_stability_behavior quorum
  source ume_consensus_sequence_number_behavior highest
  source ume_proxy_source 0
  source ume_state_lifetime 0
  source ume_activity_timeout 0
  source retransmit_retention_age_threshold 0
  source ume_store_name 
  source ume_session_id 0x0
  source use_extended_reclaim_notifications 1
  source application_data 
  source ume_receiver_paced_persistence 0
  source ume_repository_size_threshold 0
  source ume_repository_size_limit 0
  source ume_repository_disk_file_size_limit 0
  source ume_write_delay 0
  source ume_repository_ack_on_reception 0
  source ume_sri_max_number_of_sri_per_update 20
  source ume_sri_inter_sri_interval 500
  source ume_sri_request_response_latency 100
  source ume_sri_flush_sri_request_response 0
  source ume_sri_immediate_sri_request_response 1
  source ume_source_timer_minimum_interval 50
  source ume_message_stability_timeout 5000
  source ume_message_stability_lifetime 1200000
  source ume_message_stability_timeout_behavior 0
  source onload_acceleration_stack_name 
SmartSource MySmartTopic
  source transport LBT-RM
  source resolver_ttl 60
  source resolver_send_initial_advertisement 1
  source resolver_send_final_advertisements 0
  source resolver_advertisement_minimum_initial_interval 10
  source resolver_advertisement_maximum_initial_interval 500
  source resolver_advertisement_minimum_initial_duration 5000
  source resolver_advertisement_sustain_interval 1000
  source resolver_advertisement_minimum_sustain_duration 60
  source resolver_advertisement_send_immediate_response 1
  source transport_tcp_port 0
  source transport_tcp_interface 0.0.0.0
  source transport_tcp_reuseaddr 0
  source transport_tcp_exclusiveaddr 1
  source transport_tcp_nodelay 1
  source transport_tcp_sender_socket_buffer 0
  source transport_tcp_listen_backlog 5
  source transport_tcp_activity_timeout 0
  source transport_tcp_multiple_receiver_behavior normal
  source transport_tcp_multiple_receiver_send_order serial
  source transport_tcp_coalesce_threshold 1024
  source transport_tcp_use_session_id 1
  source transport_source_side_filtering_behavior none
  source transport_session_maximum_buffer 65536
  source transport_lbtrm_multicast_address 224.10.10.11
  source transport_lbtrm_tgsz 8
  source transport_lbtrm_destination_port 14400
  source transport_lbtrm_ignore_interval 500
  source transport_lbtrm_sm_minimum_interval 200
  source transport_lbtrm_sm_maximum_interval 10000
  source transport_lbtrm_transmission_window_size 25165824
  source transport_lbtrm_transmission_window_limit 0
  source transport_lbtrm_coalesce_threshold 15
  source smart_src_max_message_length 368
  source smart_src_user_buffer_count 32
  source smart_src_retention_buffer_count 1024
  source smart_src_enable_spectrum_channel 0
  source smart_src_enable_transport_compatibility 1
  source smart_src_message_property_int_count 0
  source transport_lbtrm_smart_src_transmission_window_buffer_count 16384
  source transport_lbtru_smart_src_transmission_window_buffer_count 16384
  source implicit_batching_minimum_length 2048
  source implicit_batching_interval 200
  source implicit_batching_type default
  source transport_topic_sequence_number_info_interval 5000
  source transport_topic_sequence_number_info_active_threshold 60
  source transport_lbtru_transmission_window_size 25165824
  source transport_lbtru_transmission_window_limit 0
  source transport_lbtru_client_map_size 7
  source transport_lbtru_ignore_interval 500
  source transport_lbtru_sm_minimum_interval 200
  source transport_lbtru_sm_maximum_interval 10000
  source transport_lbtru_client_activity_timeout 10000
  source transport_lbtru_port 0
  source transport_lbtru_interface 0.0.0.0
  source transport_lbtru_coalesce_threshold 15
  source transport_lbtru_use_session_id 1
  source transport_lbtipc_transmission_window_size 25165824
  source transport_lbtipc_behavior source_paced
  source transport_lbtipc_maximum_receivers_per_transport 20
  source transport_lbtipc_id 0
  source transport_lbtipc_sm_interval 10000
  source transport_lbtsmx_transmission_window_size 131072
  source transport_lbtsmx_datagram_max_size 8192
  source transport_lbtsmx_maximum_receivers_per_transport 64
  source transport_lbtsmx_id 0
  source transport_lbtsmx_sm_interval 10000
  source transport_lbtrdma_port 0
  source transport_lbtrdma_interface 0.0.0.0
  source transport_lbtrdma_transmission_window_size 25165824
  source ume_late_join 0
  source late_join 0
  source ume_confirmed_delivery_notification 0
  source ume_message_stability_notification 1
  source ume_quasar_flight_size_behavior 0
  source ume_flight_size 1000
  source ume_flight_size_bytes 0
  source ume_flight_size_behavior block
  source ume_retention_size_threshold 0
  source retransmit_retention_size_threshold 0
  source ume_retention_size_limit 25165824
  source retransmit_retention_size_limit 25165824
  source ume_retention_unique_confirmations 0
  source ume_registration_interval 3000
  source ume_message_map_tablesz 0
  source retransmit_message_map_tablesz 0
  source ume_store_check_interval 500
  source ume_store_activity_timeout 10000
  source ume_store 
  source ume_store_group 
  source ume_store_behavior quorum-consensus
  source ume_retention_intergroup_stability_behavior any-group
  source ume_retention_intragroup_stability_behavior quorum
  source ume_consensus_sequence_number_behavior highest
  source ume_proxy_source 0
  source ume_state_lifetime 0
  source ume_activity_timeout 0
  source retransmit_retention_age_threshold 0
  source ume_store_name 
  source ume_session_id 0x0
  source use_extended_reclaim_notifications 1
  source application_data 
  source ume_receiver_paced_persistence 0
  source ume_repository_size_threshold 0
  source ume_repository_size_limit 0
  source ume_repository_disk_file_size_limit 0
  source ume_write_delay 0
  source ume_repository_ack_on_reception 0
  source ume_sri_max_number_of_sri_per_update 20
  source ume_sri_inter_sri_interval 500
  source ume_sri_request_response_latency 100
  source ume_sri_flush_sri_request_response 0
  source ume_sri_immediate_sri_request_response 1
  source ume_source_timer_minimum_interval 50
  source ume_message_stability_timeout 5000
  source ume_message_stability_lifetime 1200000
  source ume_message_stability_timeout_behavior 0
  source onload_acceleration_stack_name 

CfgDump
Core-10403-150: Context (0x7f316d2d9860) created with ContextID (1188536808) and ContextName [(NULL)]
Context
  context operational_mode embedded
  context fd_management_type select
  context broker 
  context resolver_service 
  context resolver_service_interest_mode filter
  context resolver_multicast_address 224.9.10.11
  context resolver_multicast_outgoing_address 224.9.10.11
  context resolver_multicast_incoming_address 224.9.10.11
  context resolver_multicast_port 12965
  context resolver_multicast_outgoing_port 12965
  context resolver_multicast_incoming_port 12965
  context resolver_multicast_ttl 16
  context resolver_multicast_interface 192.168.158.34
  context resolver_initial_advertisements_per_second 1000
  context resolver_initial_advertisement_bps 1000000
  context resolver_sustain_advertisements_per_second 0
  context resolver_sustain_advertisement_bps 1000000
  context resolver_initial_queries_per_second 1000
  context resolver_initial_query_bps 1000000
  context resolver_sustain_queries_per_second 0
  context resolver_sustain_query_bps 1000000
  context resolver_wildcard_queries_per_second 0
  context resolver_wildcard_query_bps 1000000
  context resolver_multicast_receiver_socket_buffer 8388608
  context resolver_disable_udp_topic_resolution 0
  context transport_tcp_port_high 14390
  context transport_tcp_port_low 14371
  context transport_tcp_maximum_ports 10
  context transport_tcp_receiver_socket_buffer 0
  context request_tcp_bind_request_port 1
  context request_tcp_interface 0.0.0.0
  context request_tcp_port 14391
  context request_tcp_port_high 14395
  context request_tcp_port_low 14391
  context request_tcp_listen_backlog 5
  context request_tcp_reuseaddr 0
  context request_tcp_exclusiveaddr 1
  context response_tcp_nodelay 0
  context response_tcp_deletion_timeout 20000
  context response_session_maximum_buffer 65536
  context response_session_sender_socket_buffer 0
  context response_tcp_interface 0.0.0.0
  context transport_lbtrm_multicast_address_high 224.10.10.14
  context transport_lbtrm_multicast_address_low 224.10.10.10
  context transport_lbtrm_data_rate_limit 10000000
  context transport_lbtrm_rate_interval 10
  context transport_lbtrm_retransmit_rate_limit 5000000
  context transport_lbtrm_receiver_socket_buffer 8388608
  context transport_lbtrm_source_socket_buffer 1048576
  context transport_lbtrm_source_port_high 14399
  context transport_lbtrm_source_port_low 14390
  context delivery_control_maximum_total_map_entries 200000
  context transport_lbtrm_receiver_timestamp 0
  context transport_lbtrm_source_timestamp 0
  context mim_address 0.0.0.0
  context mim_outgoing_address 224.10.10.21
  context mim_incoming_address 0.0.0.0
  context mim_destination_port 14401
  context mim_outgoing_destination_port 14401
  context mim_incoming_destination_port 14401
  context mim_nak_backoff_interval 200
  context mim_nak_initial_backoff_interval 50
  context mim_nak_suppress_interval 1000
  context mim_nak_generation_interval 10000
  context mim_activity_timeout 60000
  context mim_send_naks 1
  context mim_tgsz 8
  context mim_ignore_interval 500
  context mim_sm_minimum_interval 200
  context mim_sm_maximum_interval 10000
  context mim_src_deletion_timeout 30000
  context mim_transmission_window_size 25165824
  context mim_transmission_window_limit 0
  context mim_implicit_batching_minimum_length 2048
  context mim_implicit_batching_interval 200
  context mim_delivery_control_order_tablesz 1031
  context mim_ordered_delivery 1
  context mim_delivery_control_activity_timeout 60000
  context mim_delivery_control_activity_check_interval 5000
  context resolver_unicast_address 0.0.0.0
  context resolver_unicast_interface 0.0.0.0
  context resolver_unicast_port 0
  context resolver_unicast_port_high 14406
  context resolver_unicast_port_low 14402
  context resolver_unicast_destination_port 15380
  context resolver_unicast_receiver_socket_buffer 8388608
  context resolver_unicast_force_alive 0
  context resolver_source_map_tablesz 131111
  context resolver_receiver_map_tablesz 131111
  context resolver_wildcard_receiver_map_tablesz 10273
  context resolver_string_hash_function murmur2
  context resolver_cache 1
  context transport_lbtru_data_rate_limit 10000000
  context transport_lbtru_rate_interval 100
  context transport_lbtru_retransmit_rate_limit 5000000
  context transport_lbtru_receiver_socket_buffer 8388608
  context transport_lbtru_source_socket_buffer 1048576
  context transport_lbtru_port_high 14389
  context transport_lbtru_port_low 14380
  context transport_lbtru_maximum_ports 5
  context transport_lbtipc_id_high 20005
  context transport_lbtipc_id_low 20001
  context transport_lbtipc_receiver_thread_behavior pend
  context transport_lbtipc_pend_behavior_linger_loop_count 1
  context transport_lbtipc_receiver_operational_mode embedded
  context transport_lbtsmx_id_high 30005
  context transport_lbtsmx_id_low 30001
  context transport_lbtsmx_receiver_operational_mode embedded
  context transport_lbtsmx_message_statistics_enabled 0
  context transport_lbtrdma_port_high 20020
  context transport_lbtrdma_port_low 20001
  context transport_lbtrdma_maximum_ports 5
  context transport_lbtrdma_receiver_thread_behavior pend
  context transport_session_multiple_sending_threads 1
  context receive_thread_pool_size 4
  context receive_thread_pool_behavior create_only
  context ume_user_receiver_registration_id 00000000
  context monitor_interval 0
  context monitor_transport lbm
  context monitor_transport_opts 
  context monitor_appid 
  context monitor_format csv
  context monitor_format_opts 
  context transport_tcp_datagram_max_size 65535
  context transport_lbtrm_datagram_max_size 8192
  context transport_lbtru_datagram_max_size 8192
  context transport_lbtipc_datagram_max_size 65535
  context transport_lbtrdma_datagram_max_size 4096
  context resolver_datagram_max_size 8192
  context source_includes_topic_index 1
  context dbl_lbtru_acceleration 0
  context dbl_lbtrm_acceleration 0
  context dbl_resolver_acceleration 0
  context dbl_mim_acceleration 0
  context ud_acceleration 0
  context disable_extended_topic_resolution_message_options 0
  context timestamp_mask 0x0
  context delivery_latency_sampling 0
  context ume_session_id 0x0
  context umq_session_id 0x0
  context network_compatibility_mode default
  context dynamic_fragmentation_reduction 0
  context compatibility_include_pre_um_6_0_behavior 0
  context compatibility_pre_um_6_0_context_ad_interval 0
  context context_name 
  context ume_ack_batching_interval 100
  context mim_delivery_control_loss_check_interval 0
  context resolver_unicast_activity_timeout 1000
  context resolver_unicast_keepalive_interval 500
  context resolver_unicast_change_interval 500
  context resolver_unicast_check_interval 200
  context resolver_unicast_daemon 
  context application_data 
  context mim_sqn_window_size 16384
  context mim_sqn_window_increment 8192
  context ume_liveness_detection_table_size 131
  context ume_receiver_liveness_interval 0
  context ume_source_liveness_timeout 0
  context resolver_ud_acceleration 0
  context resolver_context_name_query_minimum_interval 100
  context resolver_context_name_query_maximum_interval 1000
  context resolver_context_name_query_duration 0
  context resolver_context_name_activity_timeout 10000
  context delivery_control_message_batching 0
  context tls_cipher_suites TLS_DHE_RSA_WITH_AES_256_GCM_SHA384
  context ume_proactive_keepalive_interval 3000
  context tls_certificate 
  context tls_certificate_key 
  context tls_certificate_key_password 
  context tls_trusted_certificates system
  context use_tls 0
  context compression none
  context tls_compression_negotiation_timeout 5000
  context resolver_unicast_ignore_unknown_source 1
  context resolver_domain_id_active_propagation_timeout 0
  context multiple_receive_maximum_datagrams 0
  context default_interface 0.0.0.0
  context transport_lbtrm_recycle_receive_buffers 0
  context transport_lbtru_recycle_receive_buffers 0
  context transport_lbtipc_recycle_receive_buffers 0
  context transport_session_single_receiving_thread 0
  context file_descriptor_management_behavior pend
  context round_robin_xsp_count 0
Receiver MyTopic
  receiver transport_lbtrm_nak_backoff_interval 200
  receiver transport_lbtrm_nak_initial_backoff_interval 50
  receiver transport_lbtrm_nak_suppress_interval 1000
  receiver transport_lbtrm_nak_generation_interval 10000
  receiver transport_lbtrm_preactivity_timeout 0
  receiver transport_lbtrm_activity_timeout 60000
  receiver transport_lbtrm_send_naks 1
  receiver transport_tcp_interface 0.0.0.0
  receiver transport_tcp_activity_timeout 0
  receiver transport_tcp_activity_method timer
  receiver transport_tcp_dro_loss_recovery_timeout 0
  receiver delivery_control_loss_tablesz 131
  receiver delivery_control_order_tablesz 131
  receiver delivery_control_maximum_burst_loss 1024
  receiver delivery_control_loss_check_interval 0
  receiver resolution_no_source_notification_threshold 0
  receiver resolution_number_of_sources_query_threshold 10000000
  receiver resolver_query_minimum_initial_interval 20
  receiver resolver_query_maximum_initial_interval 200
  receiver resolver_query_minimum_initial_duration 5000
  receiver resolver_query_sustain_interval 1000
  receiver resolver_query_minimum_sustain_duration 60
  receiver ordered_delivery 1
  receiver transport_lbtru_nak_backoff_interval 200
  receiver transport_lbtru_nak_initial_backoff_interval 0
  receiver transport_lbtru_nak_suppress_interval 1000
  receiver transport_lbtru_nak_generation_interval 10000
  receiver transport_lbtru_activity_timeout 60000
  receiver transport_lbtru_connect_interval 100
  receiver transport_lbtru_acknowledgement_interval 500
  receiver transport_lbtru_interface 0.0.0.0
  receiver transport_lbtru_port_high 14379
  receiver transport_lbtru_port_low 14360
  receiver transport_lbtru_maximum_connect_attempts 600
  receiver transport_lbtipc_activity_timeout 60000
  receiver transport_lbtipc_dro_loss_recovery_timeout 0
  receiver transport_lbtsmx_activity_timeout 60000
  receiver ume_use_store 1
  receiver ume_use_late_join 1
  receiver use_late_join 1
  receiver ume_retransmit_request_interval 500
  receiver retransmit_request_interval 500
  receiver ume_retransmit_request_generation_interval 
  receiver retransmit_request_generation_interval 
  receiver retransmit_request_message_timeout 10000
  receiver ume_retransmit_request_maximum 0
  receiver retransmit_request_maximum 0
  receiver ume_registration_interval 3000
  receiver ume_retransmit_request_outstanding_maximum 10
  receiver retransmit_request_outstanding_maximum 10
  receiver retransmit_message_caching_proximity 5000
  receiver ume_explicit_ack_only 0
  receiver ume_consensus_sequence_number_behavior majority
  receiver hf_duplicate_delivery 0
  receiver hf_optional_messages 1
  receiver umq_hold_limit 0
  receiver umq_queue_participation 0
  receiver unrecognized_channel_behavior deliver
  receiver null_channel_behavior deliver
  receiver channel_map_tablesz 10273
  receiver use_transport_thread 0
  receiver transport_demux_tablesz 1
  receiver ume_state_lifetime 0
  receiver ume_activity_timeout 0
  receiver ume_session_id 0x0
  receiver retransmit_initial_sequence_number_request 1
  receiver ume_use_ack_batching 1
  receiver rcv_sync_cache 
  receiver rcv_sync_cache_timeout 5000
  receiver application_data 
  receiver ume_allow_confirmed_delivery 1
  receiver use_otr 2
  receiver otr_request_minimum_interval 1000
  receiver otr_request_maximum_interval 10000
  receiver otr_request_duration 
  receiver otr_request_initial_delay 2000
  receiver otr_request_outstanding_maximum 200
  receiver otr_request_log_alert_cooldown 300
  receiver otr_message_caching_threshold 10000
  receiver otr_request_message_timeout 60000
  receiver ume_receiver_paced_persistence 0
  receiver message_selector 
  receiver ume_sri_request_interval 1000
  receiver ume_sri_request_maximum 60
  receiver transport_topic_sequence_number_info_request_interval 1000
  receiver transport_topic_sequence_number_info_request_maximum 60
  receiver late_join_info_request_interval 1000
  receiver late_join_info_request_maximum 60
  receiver monitor_interval 0
  receiver onload_acceleration_stack_name 
  receiver ume_application_outstanding_maximum 0
  receiver ume_recovery_complete_event 0
Source MyTopic
  source transport LBT-RM
  source resolver_ttl 60
  source resolver_send_initial_advertisement 1
  source resolver_send_final_advertisements 0
  source resolver_advertisement_minimum_initial_interval 10
  source resolver_advertisement_maximum_initial_interval 500
  source resolver_advertisement_minimum_initial_duration 5000
  source resolver_advertisement_sustain_interval 1000
  source resolver_advertisement_minimum_sustain_duration 60
  source resolver_advertisement_send_immediate_response 1
  source transport_tcp_port 0
  source transport_tcp_interface 0.0.0.0
  source transport_tcp_reuseaddr 0
  source transport_tcp_exclusiveaddr 1
  source transport_tcp_nodelay 1
  source transport_tcp_sender_socket_buffer 0
  source transport_tcp_listen_backlog 5
  source transport_tcp_activity_timeout 0
  source transport_tcp_multiple_receiver_behavior normal
  source transport_tcp_multiple_receiver_send_order serial
  source transport_tcp_coalesce_threshold 1024
  source transport_tcp_use_session_id 1
  source transport_source_side_filtering_behavior none
  source transport_session_maximum_buffer 65536
  source transport_lbtrm_multicast_address 224.10.10.10
  source transport_lbtrm_tgsz 8
  source transport_lbtrm_destination_port 14400
  source transport_lbtrm_ignore_interval 500
  source transport_lbtrm_sm_minimum_interval 200
  source transport_lbtrm_sm_maximum_interval 10000
  source transport_lbtrm_transmission_window_size 25165824
  source transport_lbtrm_transmission_window_limit 0
  source transport_lbtrm_coalesce_threshold 15
  source smart_src_max_message_length 368
  source smart_src_user_buffer_count 32
  source smart_src_retention_buffer_count 1024
  source smart_src_enable_spectrum_channel 0
  source smart_src_enable_transport_compatibility 1
  source smart_src_message_property_int_count 0
  source transport_lbtrm_smart_src_transmission_window_buffer_count 16384
  source transport_lbtru_smart_src_transmission_window_buffer_count 16384
  source implicit_batching_minimum_length 2048
  source implicit_batching_interval 200
  source implicit_batching_type default
  source transport_topic_sequence_number_info_interval 5000
  source transport_topic_sequence_number_info_active_threshold 60
  source transport_lbtru_transmission_window_size 25165824
  source transport_lbtru_transmission_window_limit 0
  source transport_lbtru_client_map_size 7
  source transport_lbtru_ignore_interval 500
  source transport_lbtru_sm_minimum_interval 200
  source transport_lbtru_sm_maximum_interval 10000
  source transport_lbtru_client_activity_timeout 10000
  source transport_lbtru_port 0
  source transport_lbtru_interface 0.0.0.0
  source transport_lbtru_coalesce_threshold 15
  source transport_lbtru_use_session_id 1
  source transport_lbtipc_transmission_window_size 25165824
  source transport_lbtipc_behavior source_paced
  source transport_lbtipc_maximum_receivers_per_transport 20
  source transport_lbtipc_id 0
  source transport_lbtipc_sm_interval 10000
  source transport_lbtsmx_transmission_window_size 131072
  source transport_lbtsmx_datagram_max_size 8192
  source transport_lbtsmx_maximum_receivers_per_transport 64
  source transport_lbtsmx_id 0
  source transport_lbtsmx_sm_interval 10000
  source transport_lbtrdma_port 0
  source transport_lbtrdma_interface 0.0.0.0
  source transport_lbtrdma_transmission_window_size 25165824
  source ume_late_join 0
  source late_join 0
  source ume_confirmed_delivery_notification 0
  source ume_message_stability_notification 1
  source ume_quasar_flight_size_behavior 0
  source ume_flight_size 1000
  source ume_flight_size_bytes 0
  source ume_flight_size_behavior block
  source ume_retention_size_threshold 0
  source retransmit_retention_size_threshold 0
  source ume_retention_size_limit 25165824
  source retransmit_retention_size_limit 25165824
  source ume_retention_unique_confirmations 0
  source ume_registration_interval 3000
  source ume_message_map_tablesz 0
  source retransmit_message_map_tablesz 0
  source ume_store_check_interval 500
  source ume_store_activity_timeout 10000
  source ume_store 
  source ume_store_group 
  source ume_store_behavior quorum-consensus
  source ume_retention_intergroup_stability_behavior any-group
  source ume_retention_intragroup_stability_behavior quorum
  source ume_consensus_sequence_number_behavior highest
  source ume_proxy_source 0
  source ume_state_lifetime 0
  source ume_activity_timeout 0
  source retransmit_retention_age_threshold 0
  source ume_store_name 
  source ume_session_id 0x0
  source use_extended_reclaim_notifications 1
  source application_data 
  source ume_receiver_paced_persistence 0
  source ume_repository_size_threshold 0
  source ume_repository_size_limit 0
  source ume_repository_disk_file_size_limit 0
  source ume_write_delay 0
  source ume_repository_ack_on_reception 0
  source ume_sri_max_number_of_sri_per_update 20
  source ume_sri_inter_sri_interval 500
  source ume_sri_request_response_latency 100
  source ume_sri_flush_sri_request_response 0
  source ume_sri_immediate_sri_request_response 1
  source ume_source_timer_minimum_interval 50
  source ume_message_stability_timeout 5000
  source ume_message_stability_lifetime 1200000
  source ume_message_stability_timeout_behavior 0
  source onload_acceleration_stack_name 
SmartSource MySmartTopic
  source transport LBT-RM
  source resolver_ttl 60
  source resolver_send_initial_advertisement 1
  source resolver_send_final_advertisements 0
  source resolver_advertisement_minimum_initial_interval 10
  source resolver_advertisement_maximum_initial_interval 500
  source resolver_advertisement_minimum_initial_duration 5000
  source resolver_advertisement_sustain_interval 1000
  source resolver_advertisement_minimum_sustain_duration 60
  source resolver_advertisement_send_immediate_response 1
  source transport_tcp_port 0
  source transport_tcp_interface 0.0.0.0
  source transport_tcp_reuseaddr 0
  source transport_tcp_exclusiveaddr 1
  source transport_tcp_nodelay 1
  source transport_tcp_sender_socket_buffer 0
  source transport_tcp_listen_backlog 5
  source transport_tcp_activity_timeout 0
  source transport_tcp_multiple_receiver_behavior normal
  source transport_tcp_multiple_receiver_send_order serial
  source transport_tcp_coalesce_threshold 1024
  source transport_tcp_use_session_id 1
  source transport_source_side_filtering_behavior none
  source transport_session_maximum_buffer 65536
  source transport_lbtrm_multicast_address 224.10.10.11
  source transport_lbtrm_tgsz 8
  source transport_lbtrm_destination_port 14400
  source transport_lbtrm_ignore_interval 500
  source transport_lbtrm_sm_minimum_interval 200
  source transport_lbtrm_sm_maximum_interval 10000
  source transport_lbtrm_transmission_window_size 25165824
  source transport_lbtrm_transmission_window_limit 0
  source transport_lbtrm_coalesce_threshold 15
  source smart_src_max_message_length 368
  source smart_src_user_buffer_count 32
  source smart_src_retention_buffer_count 1024
  source smart_src_enable_spectrum_channel 0
  source smart_src_enable_transport_compatibility 1
  source smart_src_message_property_int_count 0
  source transport_lbtrm_smart_src_transmission_window_buffer_count 16384
  source transport_lbtru_smart_src_transmission_window_buffer_count 16384
  source implicit_batching_minimum_length 2048
  source implicit_batching_interval 200
  source implicit_batching_type default
  source transport_topic_sequence_number_info_interval 5000
  source transport_topic_sequence_number_info_active_threshold 60
  source transport_lbtru_transmission_window_size 25165824
  source transport_lbtru_transmission_window_limit 0
  source transport_lbtru_client_map_size 7
  source transport_lbtru_ignore_interval 500
  source transport_lbtru_sm_minimum_interval 200
  source transport_lbtru_sm_maximum_interval 10000
  source transport_lbtru_client_activity_timeout 10000
  source transport_lbtru_port 0
  source transport_lbtru_interface 0.0.0.0
  source transport_lbtru_coalesce_threshold 15
  source transport_lbtru_use_session_id 1
  source transport_lbtipc_transmission_window_size 25165824
  source transport_lbtipc_behavior source_paced
  source transport_lbtipc_maximum_receivers_per_transport 20
  source transport_lbtipc_id 0
  source transport_lbtipc_sm_interval 10000
  source transport_lbtsmx_transmission_window_size 131072
  source transport_lbtsmx_datagram_max_size 8192
  source transport_lbtsmx_maximum_receivers_per_transport 64
  source transport_lbtsmx_id 0
  source transport_lbtsmx_sm_interval 10000
  source transport_lbtrdma_port 0
  source transport_lbtrdma_interface 0.0.0.0
  source transport_lbtrdma_transmission_window_size 25165824
  source ume_late_join 0
  source late_join 0
  source ume_confirmed_delivery_notification 0
  source ume_message_stability_notification 1
  source ume_quasar_flight_size_behavior 0
  source ume_flight_size 1000
  source ume_flight_size_bytes 0
  source ume_flight_size_behavior block
  source ume_retention_size_threshold 0
  source retransmit_retention_size_threshold 0
  source ume_retention_size_limit 25165824
  source retransmit_retention_size_limit 25165824
  source ume_retention_unique_confirmations 0
  source ume_registration_interval 3000
  source ume_message_map_tablesz 0
  source retransmit_message_map_tablesz 0
  source ume_store_check_interval 500
  source ume_store_activity_timeout 10000
  source ume_store 
  source ume_store_group 
  source ume_store_behavior quorum-consensus
  source ume_retention_intergroup_stability_behavior any-group
  source ume_retention_intragroup_stability_behavior quorum
  source ume_consensus_sequence_number_behavior highest
  source ume_proxy_source 0
  source ume_state_lifetime 0
  source ume_activity_timeout 0
  source retransmit_retention_age_threshold 0
  source ume_store_name 
  source ume_session_id 0x0
  source use_extended_reclaim_notifications 1
  source application_data 
  source ume_receiver_paced_persistence 0
  source ume_repository_size_threshold 0
  source ume_repository_size_limit 0
  source ume_repository_disk_file_size_limit 0
  source ume_write_delay 0
  source ume_repository_ack_on_reception 0
  source ume_sri_max_number_of_sri_per_update 20
  source ume_sri_inter_sri_interval 500
  source ume_sri_request_response_latency 100
  source ume_sri_flush_sri_request_response 0
  source ume_sri_immediate_sri_request_response 1
  source ume_source_timer_minimum_interval 50
  source ume_message_stability_timeout 5000
  source ume_message_stability_lifetime 1200000
  source ume_message_stability_timeout_behavior 0
  source onload_acceleration_stack_name 
````
