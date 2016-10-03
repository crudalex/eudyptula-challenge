#!/bin/bash

set -x 

make clean && make

sudo dmesg -C
sudo ./eudyptula_load.sh

# check module installed
lsmod | grep eudy

dev=`ls /dev/eudy*`
if [ -z $dev -o ! -e $dev ]; then exit 1; fi 

# check device
ls -l /dev/eudy*

# check device readable
cat $dev

# check device writable with correct input
echo "919705445944" > $dev

# check device writable with wrong input
echo "999999999999" > $dev

sudo ./eudyptula_unload.sh
sudo dmesg 2>&1 > dmesg.log

cat dmesg.log

