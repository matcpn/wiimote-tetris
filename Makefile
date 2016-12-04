main: Board.o Game.o main.o
	g++ Board.o Game.o main.o -o main

Game.o: Game.h Game.cc
	g++ -c Game.cc -o Game.o

Board.o: Board.h Board.cc
	g++ -c Board.cc -o Board.o



clean:
	rm -rf *.o main
