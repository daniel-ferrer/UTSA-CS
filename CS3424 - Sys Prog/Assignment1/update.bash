#!bin/bash
date=$(date "+[%Y-%m-%d %H:%M:%S]")

read -p "Item Number: " itemNum
read -p "Simple Name: " newSimpleName
read -p "Item Name: " newItemName
read -p "Current quantity: " newCurrQty
read -p "Max quantity: " newMaxQty
read -p "Description: " newItemDesc

if [ -e data/$itemNum.item ]; then
{
    read itemName simpleName
    read currQty maxQty
    read itemDesc
} < data/$itemNum.item

else
    echo "ERROR: item not found"
fi

if [ -z newItemName ]; then
    newItemName = itemName
fi

if [ -z newSimpleName ]; then
    newSimpleName = simpleName
fi

if [ -z newCurrQty ]; then
    newCurrQty = currQty
fi

if [ -z newMaxQty ]; then
    newMaxQty = maxQty
fi

if [ -z newItemDesc ]; then
    newItemDesc = itemDesc
fi

if [ -e data/$itemNum.item ]; then
{
    echo "$newItemName $newSimpleName"
    echo "$newCurrQty $newMaxQty"
    echo "$newItemDesc"
    echo "UPDATED: $date - $newSimpleName" >> data/queries.log
} > data/$itemNum.item
fi
