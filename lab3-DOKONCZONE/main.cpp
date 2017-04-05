#include <iostream>
#include <fstream>
#include "kontener.hh"
#include "stos.hh"
#include "kolejka.hh"
#include "lista.hh"
#include "mierzenie.hh"


using namespace std;




int main ()
{
 
  int tab_z_ilosciami_elementow[5];
  tab_z_ilosciami_elementow[0]=10;
  tab_z_ilosciami_elementow[1]=100;
  tab_z_ilosciami_elementow[2]=1000;
  tab_z_ilosciami_elementow[3]=1000000;
  tab_z_ilosciami_elementow[4]=100000000;


  string* blad=new string();
  *blad="brak bledow";
  for (int i=0; i<3; i++)
  {
    for (int j=0; j<5; j++)
    {
    mierzenie* baza[3];
    baza[0]= new stos(tab_z_ilosciami_elementow[j]);
    baza[1]= new kolejka(tab_z_ilosciami_elementow[j]);
    baza[2]= new lista();
    baza[i]->licze_srednia(20,tab_z_ilosciami_elementow[j],blad);
    }
  }






  return 0;
}
