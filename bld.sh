#!/bin/sh
# Build json print module

# Construct table of contents for each page
for F in *.md; do :
  if egrep "<!-- mdtoc-start -->" $F >/dev/null; then :
    # Update doc table of contents (see https://github.com/fordsfords/mdtoc).
    if which mdtoc.pl >/dev/null; then mdtoc.pl -b "" $F;
    elif [ -x ../mdtoc/mdtoc.pl ]; then ../mdtoc/mdtoc.pl -b "" $F;
    else echo "FYI: mdtoc.pl not found; see https://github.com/fordsfords/mdtoc"; exit 1
    fi
  fi
done

if [ ! -f "lbm.sh" ]; then :
  echo "Must create 'lbm.sh' file (use 'lbm.sh.example' as guide)." >&2
  exit 1
fi

. ./lbm.sh

# For Linux
LIBS="-L $LBM/lib -l lbm -l pthread -l m -l rt"

rm -rf *.class cfg_dump

echo "gcc -Wall -g -I $LBM/include -I $LBM/include/lbm -o cfg_dump cfg_dump.c $LIBS"
gcc -Wall -g -I $LBM/include -I $LBM/include/lbm -o cfg_dump cfg_dump.c $LIBS
if [ $? -ne 0 ]; then echo error in cfg_dump.c; exit 1; fi

# Java: TBD
# javac $CP cfg_dump.java
# if [ $? -ne 0 ]; then echo error in lbmpong.java; exit 1; fi

