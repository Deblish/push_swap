#!/bin/bash
# This script generates a specified number of unique random numbers

NUMBERS_NEEDED=$1  # First command-line argument, specifying how many numbers to generate
declare -a numbers
count=0
max_attempts=1000
attempts=0

while [ "$count" -lt "$NUMBERS_NEEDED" ] && [ "$attempts" -lt "$max_attempts" ]; do
    num=$((RANDOM % 20000 - 10000))  # Generate random number between -10000 and 10000

    # Check if number is already in the array
    duplicate_found=0
    for i in "${numbers[@]}"; do
        if [ "$i" -eq "$num" ]; then
            duplicate_found=1
            break
        fi
    done

    # If no duplicate, add number to array and output it
    if [ "$duplicate_found" -eq 0 ]; then
        numbers+=($num)
        echo -n "$num "
        ((count++))
    fi

    ((attempts++))
done

echo  # Print a newline at the end
