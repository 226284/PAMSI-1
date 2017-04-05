#include <iostream>
#include <chrono>
#include "tablica.hh"

using namespace std;
using namespace std::chrono;
typedef duration<long long int, std::ratio<1ll, 1000000ll> > chrono_typ;


tablica::tablica(int podany_rozmiar)
{
  rozm=podany_rozmiar;
  this->wsk=new int[podany_rozmiar];
}

tablica::~tablica()
{
  delete[] wsk;
}

void tablica::przypisanie(int pozycja, int wartosc,string* blad)
{

  if(pozycja<0)
  {
    *blad="error-pozycja<0";	
    return;
  }

 
  if(pozycja<=rozm)
  {
    wsk[pozycja]=wartosc;
  }  
    else
    {
      powieksz_podwojnie(blad); //tutaj zaleznie od tego,ktory algorytm badalem, zmeinialem funkcje
    }
  
};

int tablica::odczytanie(int pozycja,string* blad)
{

  if(pozycja<0)
  {
    *blad="error-pozycja<0";	
    return 0;
  }


  if(pozycja<=rozm)
  {
    return this->wsk[pozycja];
  }  
    else
    {
      cout<<"probujesz odczytac pozycje znajdujaca sie poza zakresem tablicy"<<endl;
    }

}


int tablica::rozmiar(string* blad)
{
  if (rozm<0)
  {
    *blad="error-rozm<0";
  }
  return rozm;
}


void tablica::powieksz_o_jeden(string* blad)
{

  if (rozm<0)
  {
    *blad="error-rozm<0";
  }

  int* bufor=new int[rozm+1];
  for(int i=0; i<rozm;++i)
  {
    bufor[i]=wsk[i];
  }
  ++rozm;
  delete []wsk;
  wsk=bufor; 	

}

void tablica::powieksz_podwojnie(string* blad)
{

  if (rozm<0)
  {
    *blad="error-rozm<0";
  }

  int* bufor=new int[rozm*2];
  for(int i=0; i<rozm;++i)
  {
    bufor[i]=wsk[i];
  }
  rozm=rozm*2;
  delete []wsk;
  wsk=bufor; 	

}

void tablica::mierze_czas()
{
cout<<"chuje muje ddzikie weze" << endl;
}

void tablica::licze_srednia(int ilosc_powtorzen,int ilosc_elementow,string* blad)
{
  chrono_typ srednia;

  for(int i=0; i<ilosc_powtorzen; i++)
  {
    auto poczatek = high_resolution_clock::now();
    this->wypelniam_tablice(ilosc_elementow,blad);
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
  cout<<"srednia z virtualnej funkcji: " << srednia.count()<<endl;
}

void tablica::wypelniam_tablice(int ilosc_elementow,string* blad)
{
  for(int i=0; i<ilosc_elementow; i++)
  {
    this->przypisanie(i,i,blad);
  }

}

