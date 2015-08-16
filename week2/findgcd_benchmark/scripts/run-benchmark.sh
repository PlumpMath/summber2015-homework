#!/bin/sh


function run_benchmark() {
    local FINDGCD=$1
    for (( i = 2; i <= 9999; i++ )); do
        $FINDGCD $i  | awk '{print $7 " " $11 }'
    done
}