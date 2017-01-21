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
  int Wino::getButelki() const
  {
    return butelki;
  }
  Wino & Wino::operator=(const Wino &W)
  {
    this->marka = W.getMarka();
    this->styl = W.getStyle();
    this->butelki = W.getButelki();
    return *this;
  }
  Wino & Wino::operator+=(const Wino &W)
  {
    return Wino *A(marka,styl,butelki+W.getButelki());
  }
  Wino & Wino::operator-=(const Wino &W)
  {
    if (W.getButelki() > A.getButelki())
      return Wino *A(marka,styl,0);
    else
      return Wino *A(marka,styl,butelki - W.getButelki());
  }
  int IleButelek()
  {
    return butelki;
  }
  void Pokaz()
  {
    cout <<"Marka:\t"<<marka<<endl<<"Styl:\t"<<styl<<endl<<"Butelki\t"<butelki<<endl;
  }
ostream & operator<<(ostream & s, const Wino &W)
{
  return s<<W.marka<<","<<W.styl<<","<<W.butelki;
}

/*Wino & operator+=(const int Butle)
{
  return 
}*/