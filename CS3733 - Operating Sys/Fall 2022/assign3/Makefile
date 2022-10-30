make all: part1 part2

part1: part1.c
		gcc -o part1 part1.c

part2: part2.c
		gcc -o part2 part2.c 

clean: 
		rm -f part1 *.o
		rm -f part2 *.o 

run1: 
		./part1 part1testsequence part1-out-test
run2:
		./part1 part1sequence part1-output
		md5sum part1-output
run3:
		./part2 part2sequence part2-output
		md5sum part2-output