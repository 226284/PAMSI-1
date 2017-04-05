__start__: a.out
	./a.out

a.out:  main.o element.o stos.o lista.o kolejka.o
	g++ main.o stos.o lista.o kolejka.o element.o

main.o: main.cpp stos.hh lista.hh kolejka.hh element.hh mierzenie.hh
	g++ -c main.cpp -std=c++1y

kolejka.o: kontener.hh I_kolejka.hh kolejka.hh kolejka.cpp 
	g++ -c kolejka.cpp -std=c++1y

lista.o: kontener.hh I_lista.hh lista.hh lista.cpp 
	g++ -c lista.cpp -std=c++1y

stos.o: kontener.hh I_stos.hh stos.hh stos.cpp 
	g++ -c stos.cpp -std=c++1y

element.o: element.hh element.cpp 
	g++ -c element.cpp -std=c++1y

