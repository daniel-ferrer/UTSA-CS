#!bin/bash

read -p "Enter item number: " itemNum

if [ -e data/$itemNum.item ]; then
{
    read itemName simpleName
    read currQty maxQty
    read itemDesc
} < data/$itemNum.item
    echo "Item Name: $itemName"
    echo "Simple Name: $simpleName"
    echo "Item Number: $itemNum"
    echo "Qty: $currQty/$maxQty"
    echo "Description: $itemDesc"
else
    echo "ERROR: item not found"
fi
