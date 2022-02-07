#!bin/bash

pick=0
while [ $pick ]; do
    echo "Enter one of the following actions or press CTRL-D to exit."
    echo "C - create a new item"
    echo "R - read an existing item"
    echo "U - update an existing item"
    echo "D - delete an existing item"

    if ! read ans; then
        # EOF
        break
    fi

    case "$ans" in
        [cC]) echo "C: create a new inventory record"
            bash create.bash;;
        [rR]) echo "R: read an existing inventory item"
            bash read.bash;;
        [uU]) echo "U: update an existing inventory item"
            bash update.bash;;
        [dD]) echo "D: delete an existing inventory item"
            bash delete.bash;;
        *) echo "ERROR: invalid option";;
    esac
done
