# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = Map.h Employee.h RedBlackTree.h

# List your *.cpp files:
sources = TestMap.cpp Employee.cpp

# Specify name of your program:
executable = main

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

test: $(headers) $(sources)
	g++ -g -Wall -pedantic MyTestMap.cpp Employee.cpp -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
