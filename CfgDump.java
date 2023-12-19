/* CfgDump.java - performance measurement tool. */
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

import java.util.*;
import java.nio.*;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.atomic.AtomicInteger;
import com.latencybusters.lbm.*;

// The application class supplies the onReceive, onSourceEvent,
// onTransportMapping, and LBMLog callbacks directly.
class CfgDump implements LBMReceiverCallback {

  public static void main(String[] args) throws Exception {
    // The body of the program is in the "run" method.
    CfgDump application = new CfgDump();
    application.run(args);
  }  // main


  private void printContext(LBMContext ctx, String header)
  {
    LBMConfigOption[] opts = ctx.dumpAttributeList();
    System.out.println(header);
    for(int i=0; i<opts.length; i++) {
      System.out.println("  " + opts[i].getType() + " " + opts[i].getOptionName() + " " + opts[i].getValue());
    }
  }  // printContext


  private void printRcv(LBMReceiver rcv, String header)
  {
    LBMConfigOption[] opts = rcv.dumpAttributeList();
    System.out.println(header);
    for(int i=0; i<opts.length; i++) {
      System.out.println("  " + opts[i].getType() + " " + opts[i].getOptionName() + " " + opts[i].getValue());
    }
  }  // printRcv


  private void printSrc(LBMSource src, String header)
  {
    LBMConfigOption[] opts = src.dumpAttributeList();
    System.out.println(header);
    for(int i=0; i<opts.length; i++) {
      System.out.println("  " + opts[i].getType() + " " + opts[i].getOptionName() + " " + opts[i].getValue());
    }
  }  // printSrc


  private void printSSrc(LBMSSource ssrc, String header)
  {
    LBMConfigOption[] opts = ssrc.dumpAttributeList();
    System.out.println(header);
    for(int i=0; i<opts.length; i++) {
      System.out.println("  " + opts[i].getType() + " " + opts[i].getOptionName() + " " + opts[i].getValue());
    }
  }  // printSSrc


  private void run(String[] args) throws Exception {
    LBM lbm = new LBM();
    LBM.setConfiguration("cfg_dump.cfg");

    LBMContext myCtx = new LBMContext();
    printContext(myCtx, "Context");

    LBMTopic topicObj = myCtx.lookupTopic("MyTopic");
    LBMReceiver myRcv = myCtx.createReceiver(topicObj, this, null);
    printRcv(myRcv, "Receiver MyTopic");

    topicObj = myCtx.allocTopic("MyTopic");;
    LBMSource mySrc = myCtx.createSource(topicObj);
    printSrc(mySrc, "Source MyTopic");

    topicObj = myCtx.allocTopic("MySmartTopic");;
    LBMSSource mySSrc = new LBMSSource(myCtx, topicObj);
    printSSrc(mySSrc, "SmartSource MySmartTopic");
  }  // run

  public int onReceive(Object cbArg, LBMMessage msg) {
    msg.dispose();
    return 0;
  }  // onReceive

}  // class CfgDump
