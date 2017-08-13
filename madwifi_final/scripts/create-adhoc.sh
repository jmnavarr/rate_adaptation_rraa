
#!/usr/bin/env bash

#argument pass in
# $0 - atheroes device (e.g., ath0)
# $1 - gateway host IP (e.g., 192.168.0.1)
# $2 - client IP (e.g., 192.168.0.X)
# $3 - rate adaptation algorithm
if [ $# -eq 3 ] 
then

    echo "Atheroes Device: " $1
    echo "Gateway Host: " $2
    echo "Client Host: " $
    sudo /etc/init.d/networking restart
    sleep 1
    sudo madwifi-unload;
    sleep 1
    echo "Using AMMR (default)"
    sudo modprobe ath_pci ratectl=rraa;
    sleep 1
    sudo wlanconfig $1 destroy;
    sleep 1
    sudo wlanconfig $1 create wlandev wifi0 wlanmode adhoc;
    sleep 1
    sudo ifconfig $1 $3 netmask 255.255.255.0;
    sleep 1
    sudo route add default $1;
    sleep 1
    sudo route add default gw $2;
    sleep 1; 
    echo "Configuring channel (7)..."
    sudo iwconfig $1 channel 7;
    echo "done."
    sleep 1
    echo "Configuring essid (cs219-adhoc)..."
    sudo iwconfig $1 essid "cs219-adhoc";
    echo "done."
elif [ $# -eq 4 ]
then
    echo "Atheroes Device: " $1
    echo "Gateway Host: " $2
    echo "Client Host: " $3
    sudo /etc/init.d/networking restart
    sleep 1
    sudo madwifi-unload;
    sleep 1
    echo "Using: " $4;
    sudo modprobe ath_pci ratectl=$4;
    sleep 1
    sudo wlanconfig $1 destroy;
    sleep 1
    sudo wlanconfig $1 create wlandev wifi0 wlanmode adhoc;
    sleep 1
    sudo ifconfig $1 $3 netmask 255.255.255.0;
    sleep 1
    sudo route add default $1;
    sleep 1
    sudo route add default gw $2;
    sleep 1; 
    echo "Configuring channel (11)..."
    sudo iwconfig $1 channel 11;
    echo "done."
    sleep 1
    echo "Configuring essid (cs219-adhoc)..."
    sudo iwconfig $1 essid "cs219-adhoc";
    echo "done."
else
    echo "Invalid number of arguments: <atheros device> <gw ip> <client ip> <rate_op>"
fi