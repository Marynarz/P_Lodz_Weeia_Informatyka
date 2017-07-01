#include "Lampa.hpp"
Lampa::Lampa()
{
  Zar = new Zarowka[2];
}
Lampa::~Lampa()
{
  delete [] Zar;
}
void Lampa::UstawMocLampy(int Moc)
{
  Zar[0].UstawMoc(Moc/2);
  Zar[1].UstawMoc(Moc/2);
}
void Lampa::Wyswietl()
{
  cout <<"Moc zarowki nr. 1:" <<Zar[0].OdczytajMoc() <<endl <<"Moc Zarowki nr. 2:" <<Zar[1].OdczytajMoc() <<endl;
}