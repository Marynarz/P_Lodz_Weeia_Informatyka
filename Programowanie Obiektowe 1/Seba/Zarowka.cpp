#include "Zarowka.hpp"
Zarowka::Zarowka(int Moc):moc(Moc)
{}

void Zarowka::UstawMoc(int Moc)
{
  if(Moc >120)
    cout <<"ERROR: MOC WIEKSZA NIZ 120W! Nieustawiono"<<endl;
  else
    moc = Moc;
}

int Zarowka::OdczytajMoc()
{
  return moc;
}