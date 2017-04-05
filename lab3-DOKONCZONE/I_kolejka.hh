#ifndef I_kolejka_HH
#define I_kolejka_HH
#include "kontener.hh"

class I_kolejka: public kontener
{
  public:

  virtual void pop()=0;				// usuwa z poczatku
  virtual void push(int wartosc_dodana)=0;	// dodaje element na koniec kolejki
  virtual int end()=0;				//zwraca wartosc elementu z poczatku kolejki
  virtual ~I_kolejka(){};
};

#endif
