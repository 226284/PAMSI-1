#include <iostream>
#include "tablica.hh"

using namespace std;


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
    return wsk[pozycja];
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
