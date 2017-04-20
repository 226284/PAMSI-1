#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tablica.hh"

using namespace std;

int main() {
	srand (time(NULL) );string* blad=new string();
	*blad="brak bledow";
	int wartosci[5]= {10,100,1000,10000,100000};
	mierzenie* baza[5];
	int metoda=1;

	//for(int i=0; i<5; i++)
	//{
	//baza[i]=new tablica(wartosci[i]);
	//}

	//for(int i=0; i<5; i++)
	//{
	//baza[i]->czas_quick(20,blad);
	//}

	// Sortowanie przez scalanie
	int rozmiar = 10;
	int lewo = 0;
	int prawo = rozmiar - 1;
	tablica *tab = new tablica(rozmiar);
	//tab->pokaz();
	tab->wypelniam_tablice_losowo(rozmiar, blad);
	tab->pokaz();
	tab->mergesort(lewo, prawo);
	tab->pokaz();

	return 0;
}

