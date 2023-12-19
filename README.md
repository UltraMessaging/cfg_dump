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
