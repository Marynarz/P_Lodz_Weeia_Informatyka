#include "Wino.hpp"
  Wino::Wino(string marka,string styl, int butelki):marka(marka),styl(styl),butelki(butelki)
  {}
  Wino::~Wino()
  {}
  string Wino::getMarka() const
  {
    return marka;
  }
  string Wino::getStyle() const
  {
    return styl;
  }
  Wino & Wino::operator=(const Wino &W)
  {
    this->marka = W.getMarka();
    this->styl = W.getStyle();
    this->butelki = W.IleButelek();
    return *this;
  }
  Wino & Wino::operator+=(const int Butle)
  {
    this->butelki +=Butle;
    return *this;
  }
  Wino & Wino::operator-=(const int Butle)
  {
    if (Butle > butelki)
      this -> butelki = 0;
    else
      this -> butelki -=Butle;
    return *this;
  }
  int Wino::IleButelek() const
  {
    return butelki;
  }
  void Wino::Pokaz()
  {
    cout <<"Marka:\t"<<marka<<endl<<"Styl:\t"<<styl<<endl<<"Butelki:\t"<<butelki<<endl;
  }
ostream & operator<<(ostream & s, const Wino &W)
{
  return s<<W.marka<<","<<W.styl<<","<<W.butelki;
}

/*Wino & operator+=(const int Butle)
{
  return 
}*/