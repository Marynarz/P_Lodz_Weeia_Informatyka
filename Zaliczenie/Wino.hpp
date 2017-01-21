#ifndef Wino_hpp
#define Wino_hpp
#include <iostream>

using namespace std;

class Wino
{
private:
  string marka;
  string styl;
  int butelki;
  
public:
  Wino(string marka = "brak", string styl = "brak", int butelki = 0);
  ~Wino();
  string getMarka() const;
  string getStyle() const;
  Wino & operator=(const Wino &W);
  Wino & operator+=(const int Butle);
  Wino & operator-=(const int Butle);
  int IleButelek() const;
  void Pokaz();
  friend ostream & operator<<(ostream & s, const Wino &W);
};

#endif