#ifndef mierzenie_HH
#define mierzenie_HH
#include <iostream>
#include <fstream>

using namespace std;

class mierzenie
{

public:
  virtual void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)=0;
  virtual void wypelniam(int ilosc_elementow,string* blad)=0;
  virtual void wyswietl()=0;
};


#endif
