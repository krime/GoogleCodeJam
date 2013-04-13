#!/bin/bash

function palin() {
    m=$1
    n=${#1}
    n=$((n/2))
    echo $n
    for ((i=0;i<$n;i++)); do
        echo $m
    done
}

read i
for ((j=0;j<$i;j++)); do
    echo -n "Case #$((j+1)): "
    read a b
    # echo "$a $b"
    ar=`echo "sqrt($a)" | bc -q`
    br=`echo "sqrt($b)" | bc -q`
    # echo $ar $br
    palin $br
done
