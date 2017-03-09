#include <iostream>

using namespace std;


class tablica {
private:
  int rozm;
  int wypelnienie;
  tablica powieksz(int rozm, tablica wejsciowa);
  
public:
  void przypisanie(int pozycja, int wartosc);
  void odczytanie(int pozycja);
  int rozmiar();
  int* tab=new int[rozm];
  tablica (int rozm)
  {
    for(int i=0; i++; i<rozm)
    {
    tab[i]=0;
    }
  }

};

void tablica::przypisanie(int pozycja, int wartosc)
{
  tab[pozycja]=wartosc;
};

void tablica::odczytanie(int pozycja)
{
  cout<<tab[pozycja];
}





int main () {
  return 0;
  tablica t1(3);
  t1.przypisanie(1,1);
  t1.odczytanie(1);
}
