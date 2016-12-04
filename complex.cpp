//Wojciech Niedzielski
//
//COMPLEX number in C++
#include <iostream>
#include <math.h>

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
  int getPhase()	//pobieranie fazy
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
    cout <<"-----POROWNANIE-----"<<endl;
    bool czy = a==b;
    cout <<"a==b:\t"<<czy<<endl;
    czy = a==c;
    cout <<"a==c:\t"<<czy<<endl<<endl;
  
  return 0;
}