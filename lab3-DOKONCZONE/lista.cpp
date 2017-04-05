#include <iostream>
#include <chrono>
#include "lista.hh"

using namespace std;
using namespace std::chrono;
typedef duration<long long int, std::ratio<1ll, 1000000ll> > chrono_typ;

lista::lista()
{
  rozmiar=0;
  pierwszy=NULL;
}


void lista::add(int wartosc_dodana)
{
  ++rozmiar;
  element* nowy=new element();

  nowy->wartosc=wartosc_dodana;

  if (pierwszy==NULL)
  {
    pierwszy=nowy;		// jesli pierwszy na nic nie wskazywal, to dostaje adres "nowego" elementu, tam jest wartosc i wskaznik na null
  }

  else
  {
    element* temp = pierwszy;	// temporary - tymczasowy; dostaje on adres pierwszego elementu
    while(temp->nastepny!=NULL)
    {
      temp=temp->nastepny;	// przeskakuje po liscie az do ostatniego elemntu(ktory ma "nastepny" na NULL)
    }	
    ostatni=temp->nastepny=nowy;
    ostatni->poprzedni=temp;
    ostatni->nastepny=NULL;
    
  }

}

int lista::get()
{
  return ostatni->wartosc;
}

int lista::size()
{
  return rozmiar;
}

int lista::find(int szukana_wartosc)
{
  element *temp = pierwszy;
 
  for (int i=0; i<rozmiar-1; ++i)
  {
    if (temp->nastepny->wartosc==szukana_wartosc)
    {
    cout<<"znaleziono"<<endl;
    return temp->wartosc;
    }
    temp=temp->nastepny;
  }
  cout<<"NIE MA w liscie" << endl;

}

int lista::pierwszy_wartosc()
{
  return pierwszy->wartosc;
}

int lista::ostatni_wartosc()
{
  return ostatni->wartosc;
}

void lista::wyswietl()
{
  element *temp = pierwszy;
 
  while (temp!=NULL)
  {
    cout << temp->wartosc <<endl;
    temp=temp->nastepny;
  }
}

void lista::wypelniam(int ilosc_elementow,string* blad)
{
  for(int i=0; i<ilosc_elementow; i++)
  {
    this->add(i);
  }

}

void lista::licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)
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
  cout<<"srednia z listy(w mikrosekundach): " << srednia.count()<<" Z ILOSCIA ELEMENTOW: "<<ilosc_elementow<<endl;
}



