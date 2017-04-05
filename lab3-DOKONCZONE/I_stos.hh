#ifndef I_stos_HH
#define I_stos_HH
#include "kontener.hh"


class I_stos: public kontener
{
  public:
  virtual void pop()=0;				// usuwa ze szczytu
  virtual void push(int wartosc_dodana)=0;	// dodaje element na szczyt stosu
  virtual int top()=0;				//  pobiera wartosc elementu ze szczytu stosu
  virtual ~I_stos(){};
};



#endif
