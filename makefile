all: compile run

compile:
	g++ -I ./include/ -o ./lib/HeapTree.o -c ./src/HeapTree.cpp
	g++ -I ./include/ -o ./bin/test ./lib/HeapTree.o ./src/test.cpp

run:
	./bin/test

