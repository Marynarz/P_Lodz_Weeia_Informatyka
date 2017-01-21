#include <iostream>
#include "Starewino.hpp"


using namespace std;

int main()
{
  Wino W("Merlot","czerwone",14);
  
    W.Pokaz();
    W+=5;
    cout <<W<<endl;
    W-=20;
    cout <<W.IleButelek()<<endl<<endl<<endl;
    
    Starewino Sw("Merlot","czerwone",23,"Szato",1967);
    Sw.Pokaz();
    Sw -=30;
    cout <<Sw<<endl;
    Sw += 4;
    cout <<Sw<<endl;
    
    Starewino Sw2("Merlot","biale",23,"Szato",1967);
    Sw = Sw2;
    Sw.Pokaz();
  return 0;
}