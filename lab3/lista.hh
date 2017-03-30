#ifndef tablica_HH
#define tablica_HH
#include "kontener.hh"

#include<iostream>

class lista: public kontener
{
  public:
  void add(int wartosc_dodana);
  int get();
  int size();
  int find(int szukana_wartosc);

  int prev(); 			//zwraca wartosc nastepnego elementu 
  int next();			//zwraca wartosc poprzedniego elementu
};

#endif
