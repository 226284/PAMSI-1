#ifndef mierzenie_HH
#define mierzenie_HH
#include <iostream>
#include <fstream>

using namespace std;

class mierzenie
{

public:
  virtual void mierze_czas()=0;
  virtual void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)=0;
  virtual void wypelniam_tablice(int ilosc_elementow,string* blad)=0;
  virtual int odczytanie(int pozycja, string* blad)=0;
  virtual void przypisanie(int pozycja, int wartosc, string* blad)=0;
};


#endif
