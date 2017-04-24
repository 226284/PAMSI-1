__start__: a.out
	./a.out

a.out:  program.o tablica.o
	g++ program.o tablica.o -Wall -pedantic

program.o: program.cpp tablica.hh
	g++ -c program.cpp -std=c++1y -Wall -pedantic

tablica.o: mierzenie.hh tablica.hh tablica.cpp 
	g++ -c tablica.cpp -std=c++1y -Wall -pedantic

