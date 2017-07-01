#include <iostream>
#include "Lampa.hpp"

using namespace std;

int main()
{
  Lampa L1;
  L1.Wyswietl();
  L1.UstawMocLampy(250);
  L1.Wyswietl();
  L1.UstawMocLampy(150);
  L1.Wyswietl();
  return 0;
}
