#!/bin/bash

#$3 : time
#$9 : mac address of host
#14 : tx rate (Mbps)
echo "output format"
echo "<time> <packet_count> <tx_rate>"
echo

if [ $# -eq 2 ]
then

cat $1 | grep $2 | awk  '{print $3 " " $9 " " $12 " " $14}'

fi
