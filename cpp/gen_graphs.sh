#!/bin/bash

E_PROB="0.2"
V_COUNTS=(100 500 1000 10000 100000 1000000)
G_COUNT=10

for v in ${V_COUNTS[@]}; do
    ./kosajaru -grg "${v}" "${E_PROB}" "g${v}.txt"   
    #echo "${v}"
done

