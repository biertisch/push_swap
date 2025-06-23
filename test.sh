#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <number_of_integers>"
    exit 1
fi

n=$1

generate_unique_random_integers() {
    local count=$1
    local numbers=()

    while [ "${#numbers[@]}" -lt "$count" ]; do
        num=$(( (RANDOM << 15 | RANDOM) % 20001 - 10000 ))  # Range: -10000 to 10000
        if [[ ! " ${numbers[@]} " =~ " $num " ]]; then
            numbers+=("$num")
        fi
    done

    echo "${numbers[@]}"
}

input=$(generate_unique_random_integers "$n")

result=$(./push_swap $input | ./checker_linux $input)
echo -e "Result: $result"

count=$(./push_swap $input | wc -l)
echo -e "Number of operations: $count"
