# Define the machine object files for your program
OBJECTS = main.o routeRecords.o
# Define your include file
INCLUDES = routeRecords.h

	 # make for the executable
p2: ${OBJECTS}
	gcc -g -o p2 ${OBJECTS}

# Simple suffix rules for the .o
%.o: %.c ${INCLUDES}
	gcc -g -c $<

# Clean the .o files
clean:
	rm -f ${OBJECTS}
