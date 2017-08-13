echo "DMESG OUTPUT"
echo "-------------"
echo "Rate Algorithm: " $1
echo "RTS " $2
echo "Test Record # " $3
echo "-------------"
echo tee ~/madwifi/results_hidden/$1/$2/hidden_close_udp_r$2_$1_dmesg.txt
tail -f /var/log/messages | grep $1 | tee ~/madwifi/results_hidden/$1/$2/hidden_close_udp_r$3_$1_dmesg.txt