#include <iostream>
#include <chrono>
#include "kolejka.hh"
using namespace std::chrono;
typedef duration<long long int, std::ratio<1ll, 1000000ll> > chrono_typ;


using namespace std;

kolejka::kolejka(int rozmiar_podany)
{
  przod=0;
  tyl=0;
  wypelnienie=0;
  rozmiar_max=rozmiar_podany;
  this->wsk=new int[rozmiar_podany];
}

kolejka::~kolejka()
{
  cout<<"destruktor kolejki"<<endl;
  delete []wsk;
}

void kolejka::add(int wartosc_dodana)
{
  this->push(wartosc_dodana);
}

int kolejka::get()
{
  this->end();
}

int kolejka::size()
{
  cout<<"LICZBA ELEMENTOW W KOLEJCE: " << wypelnienie << endl;
}

int kolejka::find(int szukana_wartosc)
{
  if (wypelnienie>0)
  {
    for (int i=0; i<wypelnienie; i++)
    {
      if(wsk[i]==szukana_wartosc)
      {
      cout<<"znaleziono! na pozycji: " << i << endl;
      }
    }
  }
    else
    {
    cout<<"kolejka jest pusta" << endl;
    }

}

void kolejka::pop()
{
  if(wypelnienie>0)
  {
    przod=(przod+1)%rozmiar_max;
    wypelnienie=wypelnienie-1;
  }
    else
    {
      cout<<"nie ma nic do zdjecia"<<endl;
    }

}

void kolejka::push(int wartosc_dodana)
{
  if ( wypelnienie < rozmiar_max)
  {
    wsk[tyl]=wartosc_dodana;
    tyl=(tyl+1)%rozmiar_max;
    ++wypelnienie;
  }
    else
    {
    cout<<"BLAD! przekroczono rozmiar kolejki"<<endl;
    }
}

int kolejka::end()
{
  return wsk[wypelnienie-1];
}

void kolejka::wyswietl()
{
  int indeks;

  for (int i=0; i<wypelnienie; i++)
  {
    indeks=przod+i;
    if (przod+i>=rozmiar_max)
    {
      indeks=(przod+i)%rozmiar_max;		
    }
    cout<<wsk[indeks]<<" ";
  }
  cout << endl;
}

void kolejka::wypelniam(int ilosc_elementow,string* blad)
{
  for(int i=0; i<ilosc_elementow; i++)
  {
    this->push(i);
  }

}

void kolejka::licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)
{
  chrono_typ srednia;
  this->wypelniam(ilosc_elementow,blad);
  for(int i=0; i<ilosc_powtorzen; i++)
  {
    auto poczatek = high_resolution_clock::now();
    this->find(ilosc_elementow-1);
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
  }

  srednia=srednia/ilosc_powtorzen;
  cout<<"srednia z kolejki(w mikrosekundach): " << srednia.count()<<" Z ILOSCIA ELEMENTOW: "<<ilosc_elementow<<endl;
}

