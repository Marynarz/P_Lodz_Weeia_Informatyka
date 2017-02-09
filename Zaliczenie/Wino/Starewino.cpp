#include "Starewino.hpp"
  Starewino::Starewino():Wino("brak","brak",0),nazwa("brak"),rok(0)
  {}
  Starewino::Starewino(const char* marka, const char* styl,const unsigned int butelki,const char* nazwa,unsigned int rok):Wino(marka,styl,butelki),nazwa(nazwa),rok(rok)
  {}
  Starewino::Starewino(const Starewino &W):Wino(W.getMarka(),W.getStyle(),W.IleButelek()),nazwa(W.getNazwa()),rok(W.getRok())
  {}
  Starewino::~Starewino()
  {}
  const char* Starewino::getNazwa()const
  {
    return nazwa;
  }
  unsigned int Starewino::getRok()const
  {
    return rok;
  }
  Starewino & Starewino::operator=(const Starewino &W)
  {
    this->setMarka(W.getMarka());
    this->setStyle(W.getStyle());
    this->setButle(W.IleButelek());
    this->rok = W.getRok();
    this->nazwa = W.getNazwa();
    return *this;
  }
  
  void Starewino::Pokaz()
  {
    cout <<"Marka:\t\t"<<this->getMarka()<<endl<<"Styl:\t\t"<<this->getStyle()<<endl<<"Butelki:\t"<<this->IleButelek()<<endl<<"Nazwa:\t\t"<<nazwa<<endl<<"Rok:\t\t"<<rok<<endl;
  }
  
  ostream & operator<<(ostream & s, const Starewino &W)
  {
    return s<<W.getMarka()<<","<<W.getStyle()<<","<<W.IleButelek()<<','<<W.nazwa<<','<<W.rok;
  }