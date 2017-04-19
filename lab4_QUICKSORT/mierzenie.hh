#ifndef mierzenie_HH
#define mierzenie_HH
#include <iostream>
#include <fstream>

using namespace std;

class mierzenie
{
public:
  virtual void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)=0;

/*
czas_quick
zwraca sredni czas sortowania z okreslonej ilosci powtorzen*/ 
  virtual void czas_quick(int ilosc_powtorzen, string* blad)=0;
};


#endif
