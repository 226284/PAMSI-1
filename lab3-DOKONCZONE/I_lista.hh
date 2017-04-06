#ifndef I_lista_HH
#define I_lista_HH
#include "kontener.hh"

#include<iostream>

class I_lista: public kontener
{
  public:
  virtual int pierwszy_wartosc()=0; 			//zwraca wartosc pierwszego elementu 
  virtual int ostatni_wartosc()=0;			//zwraca wartosc ostatniego
  virtual void pop()=0;
};

#endif
