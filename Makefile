main: main.o
	g++ -g -o main main.o -std=c++11 -Wall -pedantic -lncurses

main.o: main.cpp
	g++ -g -c -o main.o main.cpp
