#include <iostream>
#include <chrono>
#include "stos.hh"

using namespace std;
using namespace std::chrono;
typedef duration<long long int, std::ratio<1ll, 1000000ll> > chrono_typ;

stos::stos(int rozmiar_podany)
{
  wypelnienie=0;
  rozmiar_max=rozmiar_podany;
  this->wsk=new int[rozmiar_podany];
}

stos::~stos()
{
  cout<<"destruktor stosu"<<endl;
  delete []wsk;
}

void stos::add(int wartosc_dodana)
{
  this->push(wartosc_dodana);
}

int stos::get()
{
  this->top();
}

int stos::size()
{
  cout<<"LICZBA ELEMENTOW NA STOSIE: " << wypelnienie << endl;
}

int stos::find(int szukana_wartosc)
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
    cout<<"stos jest pusty" << endl;
    }

}

void stos::pop()
{

  if(wypelnienie>0)
  {
  wypelnienie=wypelnienie-1;
  }
    else
    {
    cout<<"nie ma nic do zdjecia"<<endl;
    }
}

void stos::push(int wartosc_dodana)
{
  if ( wypelnienie < rozmiar_max)
  {
    wsk[wypelnienie]=wartosc_dodana;
    ++wypelnienie;
  }
    else
    {
    cout<<"BLAD! przekroczono rozmiar stosu"<<endl;
    }


}

int stos::top()
{
  return wsk[wypelnienie-1];
}

void stos::wyswietl()
{
  for(int i=0; i<wypelnienie; i++)
  {
  cout<<wsk[i]<<endl;
  } 

}

void stos::wypelniam(int ilosc_elementow,string* blad)
{
  for(int i=0; i<ilosc_elementow; i++)
  {
    this->push(i);
  }

}

void stos::licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)
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
  cout<<"srednia z stosu w (mikrosekundach) " << srednia.count()<<" Z ILOSCIA ELEMENTOW: "<<ilosc_elementow<< endl;
}


