#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
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

void tablica::wypelniam_tablice_losowo(int ilosc_elementow,string* blad)
{
  
  for(int i=0; i<ilosc_elementow; i++)
  {
    this->przypisanie(i,(( rand() % ilosc_elementow ) + 0),blad);
  }

}

void tablica::pokaz()
{
  for(int i=0; i<rozm; i++)
  {
    cout<<wsk[i]<<" ";
  }
  cout<<endl;
}



int tablica::piwot_wartosc_mediana(int lewo, int prawo)
{

  if (wsk[lewo]>= wsk[(lewo+prawo)/2] && wsk[lewo] <= wsk[prawo] || wsk[lewo]<= wsk[(lewo+prawo)/2] && wsk[lewo] >= wsk[prawo])
  {
    return wsk[lewo];
  } 

  if (wsk[prawo]>= wsk[(lewo+prawo)/2] && wsk[prawo] <= wsk[lewo] || wsk[prawo]<= wsk[(lewo+prawo)/2] && wsk[prawo] >= wsk[lewo] )
  {
    return wsk[prawo];
  } 

  if (wsk[(lewo+prawo)/2]>= wsk[lewo] && wsk[(lewo+prawo)/2] <= wsk[prawo] || wsk[(lewo+prawo)/2]<= wsk[lewo] && wsk[(lewo+prawo)/2] >= wsk[prawo])
  {
    return wsk[(lewo+prawo)/2];
  } 
}

int tablica::piwot_wartosc_losowa(int lewo, int prawo)
{
  int size = prawo - lewo;
  return wsk[rand() % size + lewo];
}

int tablica::piwot_wartosc_pierwsza(int lewo)
{
  return wsk[lewo];
}

int tablica::piwot_wartosc_ostatnia(int prawo)
{
  return wsk[prawo];
}

int tablica::piwot_wartosc_srodkowa(int lewo, int prawo)
{
  return wsk[(lewo+prawo)/2];
}

void tablica::zamiana(int a, int b)
{
  int temp=wsk[a];
  wsk[a]=wsk[b];
  wsk[b]=temp;

}

void tablica::quicksort(int lewo, int prawo)
{
  int i=lewo;
  int j=prawo;

  int piwot=this->piwot_wartosc_srodkowa(lewo,prawo);

  do
  {
    while(wsk[i]<piwot)
    {
      i++;
    }

    while(wsk[j]>piwot)
    {
      j--;
    }


    if(i<=j)			// zamiana tylko jesli te mniejsze znajduja sie w niewlasciwej polowie(i na odwrot)
    {
      zamiana(j,i);
      i++;			
      j--;
    }

  }while(i<=j);

  if(lewo<j)
  {
    quicksort(lewo,j);
  }
  
  if(prawo>i)
  {
    quicksort(i,prawo); 
  }

}

void tablica::czas_quick(int ilosc_powtorzen,string* blad)
{
  chrono_typ srednia;
  int lewo=0;
  int prawo=rozm-1;

  for(int i=0; i<ilosc_powtorzen; i++)
  {
    this->wypelniam_tablice_losowo(rozm,blad);
    auto poczatek = high_resolution_clock::now();
    this->quicksort(lewo,prawo);
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

