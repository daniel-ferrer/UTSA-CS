#!/bin/awk

#setting input field seperator
BEGIN { FS="[[:space:]]*,[[:space:]]*" }
$3 == section {
    print $2, $1, "-", $5, "-", $4
    if ( $5 <= 60 ) {
       fail++
    }
    total += $5
    count++
}
END {
    print "Fails =", fail+0
    print "Average Grade =", (count ? total / count : 0)
}
