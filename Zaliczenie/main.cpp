#include <iostream>
#include "Wino.hpp"

using namespace std;

int main()
{
  Wino w("Merlot","czerwone",20);
  w.Pokaz();
  cout <<w.IleButelek()<<endl;
  return 0;
}