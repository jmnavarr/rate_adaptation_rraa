#!/usr/bin/env bash

echo "client ip: " $1
if [ $# -eq 1 ] 
then
echo "test 1"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 2"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 3"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 4"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 5"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 6"
iperf -c $1 -u -p 50000 -t 30 -b 54000000
sleep 10;
echo "test 7"
iperf -c $1 -u -p 50000 -t 30 -b 54000000

fi
