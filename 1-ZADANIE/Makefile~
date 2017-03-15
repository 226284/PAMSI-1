__start__: a.out
	./a.out

a.out:  program.o tablica.o
	g++ program.o tablica.o 

program.o: program.cpp tablica.hh
	g++ -c program.cpp -std=c++1y

tablica.o: tablica.hh tablica.cpp
	g++ -c tablica.cpp

