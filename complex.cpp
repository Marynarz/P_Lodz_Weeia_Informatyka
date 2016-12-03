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
    cout <<"------"<<endl<<"Complex a: ";
    cout <<a <<endl;
    cout <<"Czesc rzeczywista: "<<a.getReal()<<endl;
    cout <<"Czesc urojona: "<<a.getImagine()<<endl;
    cout <<"Modul: "<<a.getMod()<<endl;
    cout <<"Faza: "<<a.getPhase()<<endl;
    cout <<"------"<<endl<<"Complex b: ";
    cout <<b<<endl;
    cout <<"Czesc rzeczywista: "<<b.getReal()<<endl;
    cout <<"Czesc urojona: "<<b.getImagine()<<endl;
    cout <<"Moudl: "<<b.getMod()<<endl;
    cout <<"Faza: "<<b.getPhase()<<endl;
    cout <<"++++++++++++++"<<endl;
    
    cout <<"-----DODAWANIE-----"<<endl;
    cout <<"c=a+b   :  ";
    ComplexC c = a+b;
    cout <<c<<endl;
    cout <<"a+=b  :  ";
    a+=b;
    cout <<a<<endl<<endl;
    
    cout <<"-----ODEJMOWANIE-----"<<endl;
    cout <<"c=a-b  :  ";
    cout <<c<<endl;
    cout <<"a-=b  :  ";
    a-=b;
    cout <<a<<endl<<endl;
    cout <<"-----POROWNANIE-----"<<endl;
    bool czy = a==b;
    cout <<"a==b  :  "<<czy<<endl;
    czy = a==c;
    cout <<"a==c  :  "<<czy<<endl<<endl;
    
    //a += b;
    //cout <<a<<endl;
   
  
  return 0;
}