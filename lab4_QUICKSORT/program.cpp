#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tablica.hh"

using namespace std;



int main () 
{
  srand( time( NULL ) );
  string* blad=new string();
  *blad="brak bledow";
  int wartosci[5]={10,100,1000,10000,100000};
  mierzenie* baza[5];
  int metoda=1;
  
  for(int i=0; i<5; i++)
  {
  baza[i]=new tablica(wartosci[i]);
  }

  for(int i=0; i<5; i++)
  {
  baza[i]->czas_quick(20,blad);
  }

  
  
  return 0;
}












