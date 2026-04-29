#!/bin/bash

E_PROBS=("0.1" "0.2" "0.4" "0.8" "1.0")
V_COUNTS=(100 500 1000 2000 4000 6000 8000 10000 20000) 

echo "Generating normal graphs"
for e_p in ${E_PROBS[@]}; do
    echo "Generating edge_prob = ${e_p} graphs"
    f_name_ext=$(echo ${e_p} | tr . _)
    for v in ${V_COUNTS[@]}; do
        f_name="ge${f_name_ext}_${v}.txt"
        echo "Generating ${f_name}"
        ./kosajaru -grg "${v}" "${e_p}" "${f_name}"   
    done
done

echo "Generating tree graphs"

LOW_HIGH=("1,1" "1,5" "10,50" "100,500")

for lh in "${LOW_HIGH[@]}"; do
    for v in "${V_COUNTS[@]}"; do
        IFS=',' read l h <<< ${lh}
        f_name="te${h}_${v}.txt"
        echo "Generating ${f_name}" 
        ./kosajaru -grt "${v}" "${l}" "${h}" "${f_name}" 
    done
done

echo "Done"
