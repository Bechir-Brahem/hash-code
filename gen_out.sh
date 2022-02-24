#!/bin/sh
g++ main.cpp -o sol -O3
rm ./tests/*.out
for filename in ./tests/*; do
    echo $filename
    ./sol < $filename >"${filename%.in}.out"
done

