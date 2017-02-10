/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#ifndef Stol_hpp
#define Stol_hpp

#include <iostream>
#include "Noga.hpp"
using namespace std;

class Stol
{
    Noga * no;
    unsigned const int iloscNog;            //zmienna dodatkowa do okreslenia wielkosci tablicy
public:
    Stol(unsigned const int iloscNog = 0);  //konstruktor
    ~Stol();                                //destruktor
    void CzyStoiRowno() const;
    void UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi) const;
};
 
#endif
