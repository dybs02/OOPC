
mapFiles = ./src/Map.h ./src/LinkedList.h

mainTest = ./src/Employee.h ./src/Employee.cpp ./tests/TestMap.cpp
listTest = ./src/LinkedList.h ./tests/TestLinkedList.cpp
mapTest = ./tests/MyTestMap.cpp
library = ./examples/Book.h ./examples/Library.cpp

main: $(mapFiles) $(mainTest)
	g++ -g -Wall -pedantic $(mapFiles) $(mainTest) -o ./out/mainTest

list: $(listTest)
	g++ -g -Wall -pedantic $(listTest) -o ./out/listTest

map: $(mapFiles) $(mapTest)
	g++ -g -Wall -pedantic $(mapFiles) $(mapTest) -o ./out/mapTest

lib: $(library)
	g++ -g -Wall -pedantic $(library) -o ./out/library

.PHONY: all
all: main list map lib

.PHONY: clean
clean:
	rm ./out/*

f?=mainTest
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./out/$(f)
