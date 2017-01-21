#include <iostream>
#include "Starewino.hpp"
#include "Wino.hpp"

using namespace std;

int main()
{
  Wino w("Merlot","czerwone",20);
  w.Pokaz();
  cout <<w.IleButelek()<<endl;
  w+=20;
  cout <<w<<endl;
  Starewino Sw("Marlot","biale",13,"Chateau",1450);
  Sw.Pokaz();
  cout <<Sw.IleButelek()<<endl;
  Sw+=23;
  cout <<Sw<<endl;
  return 0;
}