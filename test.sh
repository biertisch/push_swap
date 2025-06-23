#!/bin/bash

n=500
min=-500
max=500

declare -A seen
unique_numbers=()

while [ ${#unique_numbers[@]} -lt $n ]; do
  num=$(( RANDOM % (max - min + 1) + min ))
  if [ -z "${seen[$num]}" ]; then
    unique_numbers+=($num)
    seen[$num]=1
  fi
done

input="${unique_numbers[*]}"

output=$(./push_swap $input)
echo "$output" | ./checker_linux $input
echo "number of steps: $(echo "$output" | wc -l)"
