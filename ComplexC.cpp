#include "ComplexC.hpp"
ComplexC::ComplexC(double real, double imagine):real(real),imagine(imagine)	//mega zajebisty konstruktor - tylko z tego poziomu mozna ustawic czesc rzeczywista i urojona
  {
    /*setReal(real);
    setImagine(imagine);*/
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
  double ComplexC::getReal() const	//pobieranie czesci rzeczywistej
  {
    return real;
  }
  double ComplexC::getImagine() const	//pobieranie czesci urojonej
  {
    return imagine;
  }
  double ComplexC::getMod() const	//pobieranie modulu
  {
    return sqrt(pow(getReal(),2)+pow(getImagine(),2));
  }
  double ComplexC::getPhase() const	//pobieranie fazy
  {
    if(getReal()>=0)
      return ((atan(getImagine()/getReal()) * 180)/3.14);
    
    return (((atan(getImagine()/getReal())+3.14) *180)/3.14);
  }
  
  bool ComplexC::operator==(const ComplexC & c)	//operotor porownania
  {
    if((this -> real == c.getReal())&& (this->imagine == c.getImagine()))
      return true;
    return false;
  }
    ComplexC & ComplexC::operator+=(const ComplexC & C)	//dodawanie do klasy bazowej
    {
	this -> real +=C.getReal();
	this -> imagine += C.getImagine();
	return *this;
    }
    ComplexC & ComplexC::operator-=(const ComplexC & C)	//udejmowanie od klasy bazowej
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
   ComplexC & ComplexC::operator*=(const ComplexC & C)	//mnozenie od klasy bazowej
    {
      double a = getReal();
      double b = getImagine();
      this -> real =( a* C.getReal())-(b *C.getImagine());
      this -> imagine = (a * C.getImagine())+(b * C.getReal());
      return *this;
    }

    ComplexC & ComplexC::operator/=(const ComplexC & C)	//dzielenie do klasy bazowej
    {
      double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
      double a = getReal();
      double b = getImagine();
      this->real = ((a * C.getReal())+(b * C.getImagine()))/d;
      this->imagine = ((b * C.getReal())-(a * C.getImagine()))/d;
      return *this;
    }
    
ostream & operator<<(ostream &s,const  ComplexC & C)	//ostream do couta
{
    return s<<C.getReal()<<"+"<<C.getImagine()<<"i";
}
ComplexC operator*(const ComplexC & A,const ComplexC & C)
{
  return ComplexC(((A.getReal() * C.getReal())-(A.getImagine() *C.getImagine())),((A.getReal() * C.getImagine())+(A.getImagine() * C.getReal())));
}
ComplexC operator+(const ComplexC & a, const ComplexC & C)
{
    return ComplexC(a.getReal()+C.getReal(),a.getImagine()+C.getImagine());
}
ComplexC operator-(const ComplexC & A,const ComplexC & c)	//odejmowanie
  {
    return ComplexC((A.getReal() - c.getReal()),(A.getImagine() - c.getImagine()));
  }
ComplexC operator/(const ComplexC & A,const ComplexC & C) //dzielenie
{
  double d = pow(C.getImagine(),2) + pow(C.getReal(),2);
  double a = ((A.getReal()* C.getReal())+(A.getImagine() * C.getImagine()))/d;
  double b = ((A.getImagine() * C.getReal())-(A.getReal() * C.getImagine()))/d;
  return ComplexC(a,b);
}