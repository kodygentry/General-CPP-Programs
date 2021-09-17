a.out: main.o StringList.o newTests.o
	g++ main.o StringList.o newTests.o

main.o: main.cpp StringList.h newTests.h
	g++ -c main.cpp

StringList.o: StringList.cpp StringList.h StringNode.h
	g++ -c StringList.cpp

newTests.o: newTests.cpp newTests.h
    g++ -c newTests.cpp