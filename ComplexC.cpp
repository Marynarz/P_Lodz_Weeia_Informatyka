#include "ComplexC.hpp"
ComplexC::ComplexC(double real, double imagine)	//mega zajebisty konstruktor - tylko z tego poziomu mozna ustawic czesc rzeczywista i urojona
  {
    setReal(real);
    setImagine(imagine);
  }
ComplexC::~ComplexC()	//czy potrzebny jest destruktor?
  {
    
  }
//settery dla zmiennych
void ComplexC::setReal(int real)
  {
    this ->real = real;
  }
  void ComplexC::setImagine(int imagine)
  {
    this -> imagine = imagine;
  }
  double ComplexC::getReal()	//pobieranie czesci rzeczywistej
  {
    return real;
  }
  double ComplexC::getImagine()	//pobieranie czesci urojonej
  {
    return imagine;
  }
  double ComplexC::getMod()	//pobieranie modulu
  {
    return sqrt(pow(getReal(),2)+pow(getImagine(),2));
  }
  double ComplexC::getPhase()	//pobieranie fazy
  {
    return (atan(getReal()/getImagine()) *( 180/3.14));
  }
  
  bool ComplexC::operator==(ComplexC c)	//operotor porownania
  {
    if((this -> real == c.getReal())&& (this->imagine == c.getImagine()))
      return true;
    return false;
  }
  ComplexC ComplexC::operator+(ComplexC & c)	//dodawanie
  {
    return ComplexC((getReal() + c.getReal()),(getImagine() + c.getImagine()));
  }
  ComplexC ComplexC::operator-(ComplexC & c)	//odejmowanie
  {
    return ComplexC((getReal() - c.getReal()),(getImagine() - c.getImagine()));
  }
    ComplexC & ComplexC::operator+=(ComplexC & C)	//dodawanie do klasy bazowej
    {
	this -> real +=C.getReal();
	this -> imagine += C.getImagine();
	return *this;
    }
    ComplexC & ComplexC::operator-=(ComplexC & C)	//udejmowanie od klasy bazowej
    {
	this -> real -= C.getReal();
	this -> imagine -= C.getImagine();
	return *this;
    }
    void ComplexC::showParams()	//wyswietlanie Complexa
    {
	cout <<"-----------"<<endl;
	cout <<"Czesc rzeczywista:\t"<<getReal()<<endl;
	cout <<"Czesc urojona:\t\t"<<getImagine()<<endl;
	cout <<"Modul:\t\t\t"<<getMod()<<endl;
	cout <<"Faza:\t\t\t"<<getPhase()<<endl;
	cout <<"-----------"<<endl;
    }
    ComplexC ComplexC::operator*(ComplexC C)	//mnozenie
    {
      return ComplexC(((getReal() * C.getReal())-(getImagine() *C.getImagine())),((getReal() * C.getImagine())+(getImagine() * C.getReal())));
    }
    ComplexC & ComplexC::operator*=(ComplexC C)	//mnozenie od klasy bazowej
    {
      double a = getReal();
      double b = getImagine();
      this -> real =( a* C.getReal())-(b *C.getImagine());
      this -> imagine = (a * C.getImagine())+(b * C.getReal());
      return *this;
    }
    ComplexC ComplexC::operator/(ComplexC & C) //dzielenie
    {
      double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
      double a = ((getReal()* C.getReal())+(getImagine() * C.getImagine()))/d;
      double b = ((getImagine() * C.getReal())-(getReal() * C.getImagine()))/d;
      return ComplexC(a,b);
    }
    ComplexC & ComplexC::operator/=(ComplexC & C)	//dzielenie do klasy bazowej
    {
      double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
      double a = getReal();
      double b = getImagine();
      this->real = ((a * C.getReal())+(b * C.getImagine()))/d;
      this->imagine = ((b * C.getReal())-(a * C.getImagine()))/d;
      return *this;
    }