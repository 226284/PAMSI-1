#ifndef kolejka_HH
#define kolejka_HH
#include "kontener.hh"

class kolejka: public kontener
{
  public:
  void add(int wartosc_dodana);
  int get();
  int size();
  int find(int szukana_wartosc);

  void pop();				// dodaje element na koniec kolejki
  void push();				// usuwa element z poczatku kokejki
  int end();				//zwraca wartosc elementu z poczatku kolejki
};

#endif
