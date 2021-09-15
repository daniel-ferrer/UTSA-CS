#!bin/bash

date=$(date "+[%Y-%m-%d %H:%M:%S]")

read -p "Item Number: " itemNum
read -p "Simple Name: " simpleName
read -p "Item Name: " itemName
read -p "Current Quantity: " currQty
read -p "Max Quantity: " maxQty
read -p "Description: " itemDesc

if [ ! -e data ]; then
    mkdir -p data
    touch data/queries.log
fi

if [ -e data/$itemNum.item ]; then
    echo "ERROR: item already exists"
else
    echo "$itemName $simpleName" >> data/$itemNum.item
    echo "$currQty $maxQty" >> data/$itemNum.item
    echo "$itemDesc" >> data/$itemNum.item
    echo "CREATED: $date - $simpleName" >> data/queries.log
fi
