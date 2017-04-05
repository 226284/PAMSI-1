#ifndef kontener_HH
#define kontener_HH
#include <iostream>
#include "mierzenie.hh"



class kontener: public mierzenie		
{
  public:
  virtual void add(int wartosc_dodana)=0;	// podana wartosc dodaje do kontenera
  virtual int get()=0;				// pobiera wartosc elementu kontenera (zaleznie od tego jaki to jest typ kontenera)
  virtual int size()=0;				// zwraca rozmiar kontenera
  virtual int find(int szukana_wartosc)=0;	// zwraca szukana wartosc (jesli jest ona w kontenerze)
  virtual ~kontener(){};
};





#endif
