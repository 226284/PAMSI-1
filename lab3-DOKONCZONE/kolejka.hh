#ifndef kolejka_HH
#define kolejka_HH

#include "kontener.hh"
#include "I_kolejka.hh"

using namespace std;


class kolejka : public I_kolejka
{
  private:
  int* wsk;
  int wypelnienie;
  int rozmiar_max;
  int przod;		// pierwszy element w kolejce
  int tyl;		//pierwze wolne miejsce w kolejce
 
  public:
  kolejka(int rozmiar_podany);
  ~kolejka();
  
  void add(int wartosc_dodana);
  int get();
  int size();	
  int find(int szukana_wartosc);

  void pop();				
  void push(int wartosc_dodana);
  int end();
  void wyswietl();

  void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad);
  void wypelniam(int ilosc_elementow,string* blad);	
};


#endif
