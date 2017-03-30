#ifndef kolejka_HH
#define kolejka_HH
#include "kontener.hh"


class stos: public kontener
{
  public:
  void add(int wartosc_dodana);
  int get();
  int size();		
  int find(int szukana_wartosc);

  void pop();				// dodaje na szczyt stosu
  void push();				// usuwa element ze szczytu stosu
  int top();				//  pobiera wartosc elementu ze szczytu stosu
			
};

#endif
