# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = ./src/Map.h ./src/Employee.h ./src/LinkedList.h

# List your *.cpp files:
sources = ./tests/TestMap.cpp ./src/Employee.cpp

# Specify name of your program:
executable = main

all: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

list: $(headers) $(sources)
	g++ -g -Wall -pedantic ./tests/TestLinkedList.cpp -o $(executable)

map: $(headers) $(sources)
	g++ -g -Wall -pedantic ./tests/MyTestMap.cpp -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
