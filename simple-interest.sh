#!/usr/bin/env bash

read -r -p "Principal: " principal
read -r -p "Annual interest rate (%): " rate
read -r -p "Time period (years): " time

number_pattern='^[0-9]+([.][0-9]+)?$'

if [[ ! $principal =~ $number_pattern ||
      ! $rate =~ $number_pattern ||
      ! $time =~ $number_pattern ]]; then
    echo "Error: Please enter non-negative numbers." >&2
    exit 1
fi

LC_ALL=C awk -v p="$principal" -v r="$rate" -v t="$time" '
BEGIN {
    interest = p * r * t / 100
    printf "Simple interest: %.2f\n", interest
    printf "Total amount: %.2f\n", p + interest
}'
