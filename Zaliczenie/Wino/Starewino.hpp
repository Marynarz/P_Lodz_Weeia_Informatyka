#ifndef Starewino_hpp
#define Starewino_hpp
#include <iostream>
#include "Wino.hpp"

using namespace std;

class Starewino : public Wino
{
private:
  unsigned int rok;
  const char* nazwa;
  
public:
  Starewino();									//konstruktor pusty
  Starewino(const char* marka, const char* styl,const unsigned int butelki,const char* nazwa,unsigned int rok);
  Starewino(const Starewino &W);							//konstruktor kopiujacy
  ~Starewino();								//destruktor
  const char* getNazwa()const;
  unsigned int getRok()const;
  Starewino & operator=(const Starewino &W);
  virtual void Pokaz();
  friend ostream & operator<<(ostream & s, const Starewino &W);
};

#endif