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
  int* pom;
  void powieksz_o_jeden(string* blad);
  void powieksz_podwojnie(string* blad);
/*
ponizsze funkcje okreslaja metode doboru piwotra
*/
  int piwot_wartosc_mediana(int lewo, int prawo);
  int piwot_wartosc_losowa(int lewo, int prawo);
  int piwot_wartosc_pierwsza(int lewo);
  int piwot_wartosc_ostatnia(int prawo);
  int piwot_wartosc_srodkowa(int lewo, int prawo);

/*
zamienia miejscami elementy w tablicy o podanych adresach
*/
  void zamiana(int i, int j);
  
public:
  void przypisanie(int pozycja, int wartosc, string* blad);
  int odczytanie(int pozycja, string* blad);
  int rozmiar(string* blad);
  tablica(int rozm);
   ~tablica();
  void licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad);
  void wypelniam_tablice_losowo(int ilosc_elementow,string* blad);
  void wypelniam_tablice(int ilosc_elementow,string* blad);
  void quicksort(int lewo, int prawo);
  // Sortowanie przez scalanie
  void scal(int lewo, int srodek, int prawo);
  void mergesort(int lewo, int prawo);

/*
funckaj "pokaz" wyswietla elementy zaware w tablicy
*/
  void pokaz();
  void czas_quick(int ilosc_powtorzen,string* blad);

};

#endif
