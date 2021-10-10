#!/bin/awk
BEGIN { user[$3]++; }
/^d.*/ { userDir[$3]++; totalDir++ }
/^\-/ { userFiles[$3]++; totalFiles++ }
$1 ~ !/^[d-]/ { userOthFiles[$3]++; totalOthFiles++ }
$8 ~ /^\./ { userHiddenFiles[$3]++; totalHiddenFiles++ }
{ userTotalFStorage[$3]+=$5; totalFStorage++ }

{
{
minDate = $6
minTime = $7
}

if ($6+$7 < minDate + minTime) {
    newDate = $6; newTime = $7;
}
    newFile = $0;

}

{

{
minDate = $6
minTIme = $7
}

if ($6+$7 > minDate + minTime) {
    oldDate = $6; oldTime = $7;
}
    oldFile = $0;
}

END {
    for (var in user) {
        print "user: ", var
        if (userFile[var] > 0) {
            print "   files: "
            print "     all/hidden: (", userFiles[var], " / ",userHiddenFiles[var], ")"
        }
        if (userDir[var] > 0) {
            print "   dir: ", userDir[var]
        }
        if (userOthFiles[var] > 0) {
            print "   other: ", userOthFiles[var]
        }
        if (userTotalFStorage[var] > 0) {
            print "   file storage: ", userTotalFStorage[var], "B"
        }
        print "\n"
        totalUser++
    }
   print "oldest file:\n", oldFile
    print "newest file:\n", newFile

    print "\n"

    print "total users:\t", totalUser-1
    print "total files"
    print "   all/hidden: (", totalFiles, " / ", totalHiddenFiles, ")"
    print "total dirs:\t", totalDir
    print "total other:\t", totalOthFiles
    print "total storage:\t", totalFStorage, "B"

    print "\n"
}
