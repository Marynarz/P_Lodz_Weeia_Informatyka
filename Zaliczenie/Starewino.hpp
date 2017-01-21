#ifndef Starewino_hpp
#define Starewino_hpp
#include <iostream>

using namespace std;

class Starewino : public Wino
{
private:
  unsigned int rok;
  const char* nazwa;
  
public:
  Starewino();									//konstruktor pusty
  Starewino(const Wino &W);							//konstruktor kopiujacy
  ~StareWino();								//destruktor
  const char* getMarka()const;
  const char* getStyle()const;
  const char* getNazwa()const;
  unsigned int getRok()const;
  virtual Wino & operator=(const Starewino &W);
  virtual void Pokaz();
  friend ostream & operator<<(ostream & s, const Starewino &W);
};

#endif