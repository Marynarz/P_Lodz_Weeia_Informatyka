#ifndef Wino_hpp
#define Wino_hpp

#include <iostream>

using namespace std;

class Wino
{
private:
  char* marka;
  char* styl;
  int butelki;
  
public:
  Wino(const char* marka = "brak", const char*styl = "brak", int butelki = 0);
  ~Wino();
  Wino & operator=(const Wino &W);
  Wino & operator+=(const int Butle);
  Wino & operator-=(const int Butle);
  int IleButelek();
  void Pokaz();
  friend ostream & operator<<(ostream & s, const Wino &W);
};

ostream & operator<<(ostream & s, const Wino &W);
#endif