//Wojciech Niedzielski
//
//COMPLEX number in C++
#include <iostream>
#include <math.h>
#include "ComplexC.hpp"

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
  double getMod()	//pobieranie modulu
  {
    return sqrt(pow(getReal(),2)+pow(getImagine(),2));
  }
  double getPhase()	//pobieranie fazy
  {
    return (atan(getReal()/getImagine()) *( 180/3.14));
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
    void showParams(string name)	//wyswietlanie Complexa
    {
	cout <<"-----------"<<endl;
	cout <<"COMPLEX:\t\t"<<name<<endl;
	cout <<"Czesc rzeczywista:\t"<<getReal()<<endl;
	cout <<"Czesc urojona:\t\t"<<getImagine()<<endl;
	cout <<"Modul:\t\t\t"<<getMod()<<endl;
	cout <<"Faza:\t\t\t"<<getPhase()<<endl;
	cout <<"-----------"<<endl;
    }
    ComplexC operator*(ComplexC C)	//mnozenie
    {
      return ComplexC(((this->real * C.getReal())-(this->imagine *C.getImagine())),((this->real * C.getImagine())+(this->imagine * C.getReal())));
    }
    ComplexC & operator*=(ComplexC C)	//mnozenie od klasy bazowej
    {
      double a = this->real;
      double b = this->imagine;
      this -> real =( a
 * C.getReal())-(b *C.getImagine());
      this -> imagine = (a * C.getImagine())+(b * C.getReal());
      return *this;
    }
    ComplexC operator/(ComplexC C) //dzielenie
    {
      double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
      double a = ((this->real * C.getReal())+(this->imagine * C.getImagine()))/d;
      double b = ((this->imagine * C.getReal())-(this->real * C.getImagine()))/d;
      return ComplexC(a,b);
    }
    ComplexC & operator/=(ComplexC C)	//dzielenie do klasy bazowej
    {
      double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
      double a = this->real;
      double b = this->imagine;
      this->real = ((a * C.getReal())+(b * C.getImagine()))/d;
      this->imagine = ((b * C.getReal())-(a * C.getImagine()))/d;
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
    ComplexC b(2,1);
    
    cout <<"++++COMPLEX++++"<<endl;
    cout<<a<<endl;
    a.showParams("a");
    cout<<b<<endl;
    b.showParams("b");
    cout <<"++++++++++++++"<<endl;
    
    cout <<a <<endl<<b<<endl;
    cout <<"-----DODAWANIE-----"<<endl;
    cout <<"c=a+b:\t";
    ComplexC c = a+b;
    cout <<c<<endl;
    cout <<"a+=b:\t";
    a+=b;
    cout <<a<<endl<<endl;
            
    cout <<"-----ODEJMOWANIE-----"<<endl;
    cout <<"c=a-b:\t";
    cout <<c<<endl;
    cout <<"a-=b:\t";
    a-=b;
    cout <<a<<endl<<endl;
    
    cout <<"-----MNOZENIE-----"<<endl;
    cout <<"c=a*b:\t";
    c=a*b;
    cout <<c<<endl;
    cout <<"a*=b:\t";
    a*=b;
    cout <<a<<endl<<endl;
    
    cout <<"-----POROWNANIE-----"<<endl;
    bool czy = a==b;
    cout <<"a==b:\t"<<czy<<endl;
    czy = a==c;
    cout <<"a==c:\t"<<czy<<endl<<endl;
  
  return 0;
}