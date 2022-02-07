#!bin/bash
date=$(date "+[%Y-%m-%d %H:%M:%S]")

read -p "Enter an item number: " itemNum

if [ -e data/$itemNum.item ]; then
{
    read itemName simpleName
    read currQty maxQty
    read itemDesc

    rm -r data/$itemNum.item
    echo "DELETED: $date - $simpleName" >> data/queries.log
    echo "$simpleName was successfully deleted."
} < data/$itemNum.item
else
    echo "ERROR: item not found"
fi
