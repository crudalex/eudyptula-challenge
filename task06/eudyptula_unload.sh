#!/bin/sh
#set -x

module="eudyptula"
device="eudyptula"

sudo rm -f /dev/${device}
sudo rmmod ${module}

