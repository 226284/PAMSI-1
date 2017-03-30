__start__: a.out
	./a.out

a.out:  main.o stos.o lista.o kolejka.o
	g++ main.o stos.o lista.o kolejka.o

main.o: main.cpp stos.hh lista.hh kolejka.hh
	g++ -c main.cpp -std=c++1y

kolejka.o: kontener.hh kolejka.hh kolejka.cpp 
	g++ -c kolejka.cpp -std=c++1y

lista.o: kontener.hh lista.hh lista.cpp 
	g++ -c lista.cpp -std=c++1y

stos.o: kontener.hh stos.hh stos.cpp 
	g++ -c stos.cpp -std=c++1y

