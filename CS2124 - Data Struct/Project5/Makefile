# Define the machine object files for your program
OBJECTS = tfe646Project5.o HashTable.o
# Define your include file
INCLUDES = HashTable.h

# make for the executable
p5: ${OBJECTS}
	gcc -g -o p5 ${OBJECTS} -lm

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c -O3 -lm $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
