#include <iostream>
#include <fstream>
#include <chrono>
#include "tablica.hh"

using namespace std;


void wypelnij_tablice(tablica* wsk_tab,string* blad)
{
  for(int i=0;i<1000000;i++)
  {
    wsk_tab->przypisanie(i,i,blad);
  }
}



int main () {
  using namespace std::chrono;
  string* blad=new string();
  *blad="";
  duration<long long int, std::ratio<1ll, 1000000ll> > srednia;

  for(int i=0;i<20;i++)
  {
    tablica t1(10);
    tablica* wsk_tab=&t1;

    auto poczatek = high_resolution_clock::now();
    wypelnij_tablice(wsk_tab,blad);
    auto koniec = high_resolution_clock::now();
    auto roznica = duration_cast<microseconds>(koniec-poczatek);

    if(i==0)
    {
      srednia=roznica; 
    }
      else
      {
        srednia+=roznica;
      }
    cout << "czas trwania: " << roznica.count() << " microsekund"<<endl;
  }


  srednia=srednia/20;
  cout << "SREDNIA: " << srednia.count() << " microsekund"<<endl;
  delete blad;
  return 0;
}












