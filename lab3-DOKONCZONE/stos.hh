#ifndef stos_HH
#define stos_HH
#include "kontener.hh"
#include "I_stos.hh"

using namespace std;


class stos : public I_stos
{
  private:
  int* wsk;
  int wypelnienie;
  int rozmiar_max;
 
  public:
  stos(int rozmiar_podany);
  ~stos();
  
  void add(int wartosc_dodana);
  int get();
  int size();	
  int find(int szukana_wartosc);

  void pop();				
  void push(int wartosc_dodana);
  int top();
  void wyswietl();

  void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad);
  void wypelniam(int ilosc_elementow,string* blad);
};



#endif
