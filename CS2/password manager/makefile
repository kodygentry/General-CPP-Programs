a.out: main.o user.o
	g++ main.o user.o

main.o: main.cpp user.h
	g++ -c main.cpp

user.o: user.cpp user.h
	g++ -c -std=c++11 user.cpp
