#ifndef tablica_HH
#define tablica_HH

#include<iostream>
#include "mierzenie.hh"

using namespace std;




class tablica : public mierzenie{
private:
  int rozm;
  int wypelnienie;
  int* wsk;
  void powieksz_o_jeden(string* blad);
  void powieksz_podwojnie(string* blad);
  
public:
  void przypisanie(int pozycja, int wartosc, string* blad);
  int odczytanie(int pozycja, string* blad);
  int rozmiar(string* blad);
  tablica(int rozm);
   ~tablica();
  void mierze_czas();
  void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad);
  void wypelniam_tablice(int ilosc_elementow,string* blad);

};

#endif
