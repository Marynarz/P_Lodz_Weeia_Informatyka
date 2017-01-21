#include "Wino.hpp"
  Wino::Wino(const char* marka,const char* styl,const unsigned int butelki):marka(marka),styl(styl),butelki(butelki)
  {}
  Wino::Wino(const Wino &W):marka(W.getMarka()),styl(W.getStyle()),butelki(W.IleButelek())
  {}
  Wino::~Wino()
  {}
  const char* Wino::getMarka()const
  {
    return marka;
  }
  const char* Wino::getStyle()const
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
  Wino & Wino::operator+=(const unsigned int Butle)
  {
    this->butelki +=Butle;
    return *this;
  }
  Wino & Wino::operator-=(const unsigned int Butle)
  {
    if (Butle > butelki)
      this -> butelki = 0;
    else
      this -> butelki -=Butle;
    return *this;
  }
  unsigned int Wino::IleButelek() const
  {
    return butelki;
  }
  void Wino::Pokaz()
  {
    cout <<"Marka:\t\t"<<marka<<endl<<"Styl:\t\t"<<styl<<endl<<"Butelki:\t"<<butelki<<endl;
  }
ostream & operator<<(ostream & s, const Wino &W)
{
  return s<<W.marka<<","<<W.styl<<","<<W.butelki;
}
