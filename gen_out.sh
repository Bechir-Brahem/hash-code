#!/bin/sh
mkdir outputs
for filename in ./tests/*; do
    ./sol < $filename >./ouputs/"${filename%.in}.out"
done

