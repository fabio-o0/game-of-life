life: main.cpp Renderer.o Grid.o
	g++ -o life main.cpp Renderer.o Grid.o -std=c++11 -Wall -pedantic -lncurses

Renderer.o: Renderer.cpp Grid.o
	g++ -c Renderer.cpp Grid.o

Grid.o: Grid.cpp
	g++ -c Grid.cpp
