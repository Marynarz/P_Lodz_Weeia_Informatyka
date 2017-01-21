  Starewino();									//konstruktor pusty
  Starewino(const Wino &W);							//konstruktor kopiujacy
  ~StareWino();								//destruktor
  const char* getMarka()const;
  const char* getStyle()const;
  const char* getNazwa()const;
  Wino & Starewino::operator=(const Starewino &W)
  {
    this->marka = W.getMarka();
    this->styl = W.getStyle();
    this->butelki = W.IleButelek();
    this->rok = W.getRok();
    this->nazwa = W.getNazwa();
    return *this;
  }
  
  void Starewino::Pokaz()
  {
    cout <<"Marka:\t\t"<<marka<<endl<<"Styl:\t\t"<<styl<<endl<<"Butelki:\t"<<butelki<<endl<<"Nazwa:\t\t"<<nazwa<<endl<<"Rok:\t\t"<<rok<<endl;
  }
  
  ostream & operator<<(ostream & s, const Starewino &W)
  {
    return s<<W.marka<<","<<W.styl<<","<<W.butelki<<','<<W.nazwa<<','<<W.rok;
  }