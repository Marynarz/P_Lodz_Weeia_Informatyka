#ifndef Wino_hpp
#define Wino_hpp
#include <iostream>

using namespace std;

class Wino
{
private:
  const char* marka;
  const char* styl;
  int butelki;
  
public:
  Wino(const char* marka = "brak", const char* styl = "brak",const int butelki = 0);	//konstruktor z wartosciami domyslnymi
  Wino(const Wino &W);							//konstruktor kopiujacy
  ~Wino();								//destruktor
  const char* getMarka()const;
  const char* getStyle()const;
  Wino & operator=(const Wino &W);
  Wino & operator+=(const int Butle);
  Wino & operator-=(const int Butle);
  int IleButelek() const;
  void Pokaz();
  friend ostream & operator<<(ostream & s, const Wino &W);
};

#endif