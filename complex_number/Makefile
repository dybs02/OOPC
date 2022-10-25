# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = complex.h

# List your *.c files:
sources = test.cpp complex.cpp

# Specify name of your program:
executable = main

all: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
