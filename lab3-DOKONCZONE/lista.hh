#ifndef lista_HH
#define lista_HH
#include "kontener.hh"
#include "I_lista.hh"
#include "element.hh"

#include<iostream>




class lista: public I_lista
{
  private:
  element* pierwszy;
  element* ostatni;
  int rozmiar;

  public:
  lista();

  void add(int wartosc_dodana);
  int get();
  int size();
  int find(int szukana_wartosc);

  int pierwszy_wartosc(); 			//zwraca wartosc nastepnego elementu 
  int ostatni_wartosc();			//zwraca wartosc poprzedniego elementu

  void wyswietl();

  void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad);
  void wypelniam(int ilosc_elementow,string* blad);
};

#endif
