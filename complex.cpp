//Wojciech Niedzielski
//
//COMPLEX number in C++
#include <iostream>

using namespace std;

class ComplexC
{
private:	//zmienne
  double real;
  double imagine;

public:
  ComplexC(double real =0, double imagine =0)	//mega zajebisty konstruktor - tylko z tego poziomu mozna ustawic czesc rzeczywista i urojona
  {
    setReal(real);
    setImagine(imagine);
  }
  ~ComplexC()	//czy potrzebny jest destruktor?
  {
    
  }
private:	//settery dla zmiennych
  void setReal(int real)
  {
    this ->real = real;
  }
  void setImagine(int imagine)
  {
    this -> imagine = imagine;
  }
public:
  double getReal()	//pobieranie czesci rzeczywistej
  {
    return real;
  }
  double getImagine()	//pobieranie czesci urojonej
  {
    return imagine;
  }
  friend ostream & operator<<(ostream &s, const ComplexC &C);	//ostream do cout-a
  bool operator==(ComplexC c)	//operotor porownania
  {
    if((this -> real == c.getReal())&& (this->imagine == c.getImagine()))
      return true;
    return false;
  }
  ComplexC operator+(ComplexC c)	//dodawanie
  {
    return ComplexC(this-> real + c.getReal(),this-> imagine + c.getImagine());
  }
  ComplexC operator-(ComplexC c)	//odejmowanie
  {
    return ComplexC(this-> real - c.getReal(),this-> imagine - c.getImagine());
  }
    ComplexC & operator+=(ComplexC C)	//dodawanie do klasy bazowej
    {
	this -> real +=C.getReal();
	this -> imagine += C.getImagine();
	return *this;
    }
    ComplexC & operator-=(ComplexC C)	//udejmowanie od klasy bazowej
    {
	this -> real -= C.getReal();
	this -> imagine -= C.getImagine();
	return *this;
    }
};
ostream & operator<<(ostream &s, ComplexC & C)	//ostream do couta
{
    return s<<C.getReal()<<"+"<<C.getImagine()<<"i";
}
  
int main()
{
  ComplexC a(1,1);
  ComplexC b(1,1);
  a += b;
    cout <<a<<endl;
   
  
  return 0;
}