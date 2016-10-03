#!/bin/sh

#set -x

module="eudyptula"
device="eudyptula"
mode="666"

# /sbin/insmod -f $module || exit 1
sudo /sbin/insmod ${module}.ko || exit 1

minor=`cat /proc/misc | awk "\\$2==\"$module\" {print \\$1}"`
minor=`cat /proc/misc | awk "\\$2==\"$module\" {print \\$1}"`

sudo rm -f /dev/${device}
sudo mknod /dev/${device} c 10 $minor
sudo chmod $mode /dev/${device}
