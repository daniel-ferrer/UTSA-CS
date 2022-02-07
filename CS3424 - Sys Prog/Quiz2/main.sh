#!/bin/bash

count=0
pos=1

while read line
do
    if((pos % 3 != 0)); then
        echo "$line"
        ((count+=1))
    fi
    ((pos+=1))
done

if((count > 10)); then
    echo "big"
else
    echo "small"
fi

