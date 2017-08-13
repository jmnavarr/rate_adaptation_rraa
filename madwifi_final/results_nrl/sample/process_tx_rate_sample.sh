#!/bin/bash

#$3 : time
#$9 : mac address of host
#14 : tx rate (Mbps)
echo "output format"
echo "<time> <packet count> <tx rate>"
echo

if [ $# -eq 2 ]
then

cat $1 | grep $2 | awk  '{print $3 " " $13 " " $11}'

fi
