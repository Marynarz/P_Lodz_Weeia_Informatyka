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
  friend ostream & operator<<(ostream &s, const ComplexC &C);
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
 /* ComplexC & operator++()
  {
    this->real++;
    this->imagine++;
    return *this;
  }
  ComplexC operator++(int)
  {
    ComplexC
  }
  ComplexC operator--()
  {
    return ComplexC(this-> real-1, this->imagine -1);
    }
  */
};
ostream & operator<<(ostream &s, ComplexC & C)
{
    return s<<C.getReal()<<"+"<<C.getImagine()<<"i";
}
  
int main()
{
  ComplexC a(1,1);
  ComplexC b(1,1);
  ComplexC c = a+b;
    cout <<c<<endl;
   
  
  return 0;
}