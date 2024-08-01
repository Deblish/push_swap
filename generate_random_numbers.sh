#!/bin/bash

# This script generates n random numbers in the range from -10000 to 10000 and outputs them in a single line list format
# It ensures that no number is repeated using a method compatible with older versions of Bash.

# Check if the user provided the number of random numbers to generate
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number_of_random_numbers>"
    exit 1
fi

n=$1 # The number of random numbers to generate
output=() # Initialize the output array

function contains {
    local e match="$1"
    shift
    for e; do [[ "$e" == "$match" ]] && return 0; done
    return 1
}

while [ ${#output[@]} -lt $n ]; do
    # Generate a random number from 0 to 32767
    num=$RANDOM

    # Transform the number to the range from -10000 to 10000
    result=$(( num % 20001 - 10000 ))

    # Check if the number has been seen already
    if ! contains "$result" "${output[@]}"; then
        output+=($result)  # Add the number to the output array
    fi
done

# Convert the array to a space-separated string
echo "${output[*]}"

