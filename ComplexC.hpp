#ifndef ComplexC_hpp
#define ComplexC_hpp

#include <iostream>
#include <math.h>
using namespace std;
class ComplexC
{
private:	//zmienne
  double real;
  double imagine;

public:
  ComplexC(double real =0, double imagine =0);	//mega zajebisty konstruktor - tylko z tego poziomu mozna ustawic czesc rzeczywista i urojona
  ~ComplexC();	//czy potrzebny jest destruktor?
private:	//settery dla zmiennych
  void setReal(int real);
  void setImagine(int imagine);
public:
  double getReal();
  double getImagine();
  double getMod();
  double getPhase();
  bool operator==(ComplexC c);
  ComplexC operator+(ComplexC & c);
  ComplexC operator-(ComplexC & c);
  ComplexC & operator+=(ComplexC & C);
  ComplexC & operator-=(ComplexC & C);
  void showParams();
  ComplexC operator*(ComplexC C);
  ComplexC & operator*=(ComplexC C);
  ComplexC operator/(ComplexC & C);
  ComplexC & operator/=(ComplexC & C);
  friend ostream & operator<<(ostream &s, const ComplexC &C);
  friend int operator*(int a, ComplexC C);
};
#endif