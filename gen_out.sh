#!/bin/sh
g++ score.cpp -o sol -O3
mkdir outputs
for filename in ./tests/*; do
    ./sol < $filename >"${filename%.in}.out"
done

