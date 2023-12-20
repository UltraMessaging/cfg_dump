#!/bin/sh
# tst.sh

if [ ! -f "lbm.sh" ]; then :
  echo "Must create 'lbm.sh' file (use 'lbm.sh.example' as guide)." >&2
  exit 1
fi

. ./lbm.sh

echo "cfg_dump"
./cfg_dump
echo ""

echo "CfgDump"
java $CP CfgDump
echo ""
