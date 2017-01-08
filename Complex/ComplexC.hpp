#ifndef ComplexC_hpp
#define ComplexC_hpp

#include <iostream>
#include <math.h>
using namespace std;
class ComplexC
{
private:
  double real;
  double imagine;

public:
  ComplexC(double real =0, double imagine =0);
  ~ComplexC();
private:
  void setReal(int real);
  void setImagine(int imagine);
public:
  double getReal() const;
  double getImagine() const;
  double getMod() const;
  double getPhase() const;
  bool operator==(const ComplexC & c);
  ComplexC & operator+=(const ComplexC & C);
  ComplexC & operator-=(const ComplexC & C);
  void showParams();
  ComplexC & operator*=(const ComplexC & C);
  ComplexC & operator/=(const ComplexC & C);
  friend ostream & operator<<(ostream &s, const ComplexC &C);
};

//ostream & operator<<(ostream &s,const ComplexC & C);	//ostream do couta
ComplexC operator*(const ComplexC & A, const ComplexC & C);
ComplexC operator+(const ComplexC & a, const ComplexC & C);
ComplexC operator-(const ComplexC & A, const ComplexC & c);	//odejmowanie
ComplexC operator/(const ComplexC & A, const ComplexC & C); //dzielenie
#endif