#include <iostream>

using namespace std;

class ComplexC
{
private:
  double real;
  double imagine;

public:
  ComplexC(double real =0, double imagine =0)
  {
    setReal(real);
    setImagine(imagine);
  }
  ~ComplexC()
  {
    
  }
private:
  void setReal(int real)
  {
    this ->real = real;
  }
  void setImagine(int imagine)
  {
    this -> imagine = imagine;
  }
public:
  double getReal()
  {
    return real;
  }
  double getImagine()
  {
    return imagine;
  }
  ostream& operator<<(ostream &s)
  {
     s<<this->getReal()<<"+"<<this->getImagine()<<"i";
    return s;
  }
  bool operator==(ComplexC c)
  {
    if((this -> real == c.getReal())&& (this->imagine == c.getImagine()))
      return true;
    return false;
  }
  ComplexC operator+(ComplexC c)
  {
    return ComplexC(this-> real + c.getReal(),this-> imagine + c.getImagine());
  }
  ComplexC operator-(ComplexC c)
  {
    return ComplexC(this-> real - c.getReal(),this-> imagine - c.getImagine());
  }
  
};
  
int main()
{
  ComplexC a(1,1);
  ComplexC b(1,1);
  bool co = a==b;
  cout <<co;
  
  return 0;
}