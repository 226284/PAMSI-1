
#ifndef tablica_HH

#define tablica_HH

#include<iostream>

using namespace std;

class tablica {

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

};

#endif
