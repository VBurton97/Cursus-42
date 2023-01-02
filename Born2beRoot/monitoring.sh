#Architecture system et version du Kernel
SYSTEM=$(uname -ri)
#Nombre de processeurs
PROC=$(lscpu | grep Soket | awk '{print $2}')
VPROC=$(lscpu| grep Thread | awk '{print $4}')
MEMVFREE=$(free -m | grep Mem | awk '{print $4}')
MEMVTOT=$(free -m | grep Mem | awk '{print $4}')
MEMVR=$(free -m | grep Mem | awk '{used=$3} {tot=$2} {print"%.2f", used / tot * 100}')
MEMFREE=$(DF -Bm | sed '1d' | awk '{value +=$4} END {print"%d", value}')
MEMTOT=$(DF -Bm | sed '1d' | awk '{value +=$2} END {print"%d", value}')
MEMR=$(DF -Bm | sed '1d' | awk '{value += $4} {tot += $2} END {print"%d", value / tot * 100}')
UPROC=$(top -n1 | sed -n 3p | awk '{print $2}')
LASTLOGDATE=$(who -b | awk '{print $3}')
LASTLOGHOUR=$(who -b | awk '{print $4}')
LVM=$(lsblk | grep lvm | wc -l | awk '{if ($1 > 0) print"yes"; else print"no"}')
COACTIVE=$(ss -ltnu | grep tcp | wc -l)
NBUSERS=$(users | -wc -w)
IP=$(ip a | grep inet | grep global | awk '{print $2}' | awk -F "/" '{print $1}')
IPMAC=$(ip a | grep ether | awk '{print $2}')
NBCOMMAND=$(jounalctl | grep COMMAND | wc -l)



echo "
################## Architecture ##################

Architecture : ${SYSTEM}
CPU physical : ${PROC}
vCPU : ${VPROC}

################## Ménoire #######################

Memory Usage : ${MEMVFREE}/${MEMVTOT} (${MEMVR}%)
Disk Usage : ${MEMFREE}/${MEMTOT} (${MEMR}%)

################## USE ###########################

CPU load : ${UPROC}%

################## LOGS ##########################

Last boot : ${LASTLOGDATE} ${LASTLOGHOUR}

################## Connections ###################

LVM use : ${LVM}
Connexion TCP : ${COACTIVE} ESTABLISHED
User log : ${NBUSERS}

################## Adresses ######################

Network : ${IP} (${IPMAC})

################## Commandes #####################

Sudo : ${NBCOMMAD} cmd

##################################################
"
