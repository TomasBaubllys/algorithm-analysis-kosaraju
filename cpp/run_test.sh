#!/bin/bash

TEST_FILES=$(ls | grep -E "^ge[0-9]_[0-9]+_[0-9]+.txt$" | sort -V)
OUT_FILES=("data01.csv" "data02.csv" "data04.csv" "data08.csv" "data10.csv")

#Run the normal graph test
for out_file in ${OUT_FILES[@]}; do
    echo -n "" > "${out_file}" 
    if [[ "$out_file" == "data01.csv" ]]; then
        pattern="ge0_1"
    elif [[ "$out_file" == "data02.csv" ]]; then
        pattern="ge0_2"
    elif [[ "$out_file" == "data04.csv" ]]; then
        pattern="ge0_4"
    elif [[ "$out_file" == "data08.csv" ]]; then
        pattern="ge0_8"
    elif [[ "$out_file" == "data10.csv" ]]; then
        pattern="ge1_0"
    fi

    for file in $(echo "${TEST_FILES}"); do
        if [[ "$file" =~ $pattern ]]; then
            n=$(echo "${file}" | grep -oE "[0-9]+" | tail -n -1)   
            echo -n "${n}," >> "${out_file}"
            ./kosajaru -gf "${file}" >> "${out_file}"
        fi
    done
done


# run the tree graph test
TTEST_FILES=$(ls | grep -E "^te[0-9]+_[0-9]+.txt$" | sort -V)
#echo "${TTEST_FILES}"
TOUT_FILES=("tdata1.csv" "tdata5.csv" "tdata50.csv" "tdata500.csv")
for out_file in ${TOUT_FILES[@]}; do 
    echo -n "" > "${out_file}"
    if [[ "$out_file" == "tdata1.csv" ]]; then
        pattern="te1_"
    elif [[ "$out_file" == "tdata5.csv" ]]; then
        pattern="te5_"
    elif [[ "$out_file" == "tdata50.csv" ]]; then
        pattern="te50_"
    elif [[ "$out_file" == "tdata500.csv" ]]; then
        pattern="te500_"
    fi

    for tfile in $TTEST_FILES; do
        if [[ "$tfile" =~ $pattern ]]; then
            n=$(echo "${tfile}" | grep -oE "[0-9]+" | tail -n -1)
            echo -n "${n}," >> "${out_file}"
            ./kosajaru -gf "${tfile}" >> "${out_file}" 
        fi
    done
done
