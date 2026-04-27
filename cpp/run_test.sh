#!/bin/bash

TEST_FILES=$(ls | grep -E "^g[0-9]+.txt$" | sort -V)
OUT_FILE="data.csv"

echo -n "" > "${OUT_FILE}" 

for file in $TEST_FILES; do
    n=$(echo "${file}" | grep -oE "[0-9]+")   
    echo -n "${n}," >> $OUT_FILE
    ./kosajaru -gf "${file}" >> "${OUT_FILE}"
done
