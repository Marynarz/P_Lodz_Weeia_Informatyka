#ifndef Lampa_hpp
#define Lampa_hpp

#include <iostream>
#include "Zarowka.hpp"

using namespace std;

class Lampa
{
    Zarowka * Zar;
public:
    Lampa();
    ~Lampa();
    void UstawMocLampy(int Moc);
    void Wyswietl();
};

#endif