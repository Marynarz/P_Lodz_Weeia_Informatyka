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
  double getMod();
  double getPhase();
  bool operator==(ComplexC c);
  //ComplexC operator+(ComplexC & c);
  //ComplexC operator-(ComplexC & c);
  ComplexC & operator+=(ComplexC & C);
  ComplexC & operator-=(ComplexC & C);
  void showParams();
  //ComplexC operator*(ComplexC C);
  ComplexC & operator*=(ComplexC C);
  //ComplexC operator/(ComplexC & C);
  ComplexC & operator/=(ComplexC & C);
  friend ostream & operator<<(ostream &s, const ComplexC &C);
};

ostream & operator<<(ostream &s,const ComplexC & C);	//ostream do couta
ComplexC operator*(const ComplexC & A, const ComplexC & C);
ComplexC operator+(ComplexC a, ComplexC C);
ComplexC operator-(ComplexC A,ComplexC c);	//odejmowanie
ComplexC operator/(ComplexC A, ComplexC C); //dzielenie
#endif