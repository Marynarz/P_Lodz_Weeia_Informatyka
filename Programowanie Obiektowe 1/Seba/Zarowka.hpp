#ifndef Zarowka_hpp
#define Zarowka_hpp

#include <iostream>

using namespace std;

class Zarowka
{
    int moc;
public:
    Zarowka(int Moc = 100);
    void UstawMoc(int Moc);
    int OdczytajMoc();
};

#endif