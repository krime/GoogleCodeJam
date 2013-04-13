#!/bin/bash

declare -a arr=({0..15})
declare -a brd[16]
function Swap() {
    t=${arr[$1]};
    arr[$1]=${arr[$2]};
    arr[$2]=$t;
}
function Flush() {
    for i in {15..1}; do
        k=$(($RANDOM % $i))
        Swap $i $k
    done
}

Flush
# echo ${arr[*]}

# t=$(($RANDOM%16))
# echo $t
for i in {0..15}; do
    brd[$i]='.'
done
brd[${arr[0]}]='T'
# echo ${arr[$t]}
# brd[${arr[$t]}]='T'
k=15 # $(($RANDOM%16))
r=$(($k/2))
s=$(($k-$r))
# echo $r $s
for ((i=0;i<$s;i++)); do
    brd[${arr[$((i))]}]='X'
done
for ((i=0;i<$r;i++)); do
    brd[${arr[$((i+s))]}]='O'
done

echo
for ((i=0;i<4;i++)); do
    for ((j=0;j<4;j++)); do
        echo -n ${brd[$((i*4+j))]}
    done
    echo
done
# echo ${arr[*]}
