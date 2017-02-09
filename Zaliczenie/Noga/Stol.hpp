#ifndef Stol_hpp
#define Stol_hpp

#include <iostream>
#include "Noga.hpp"
using namespace std;

class Stol
{
    Noga * no;
public:
    Stol(unsigned const int iloscNog);
    ~Stol();
    void CzyStoiRowno();
    void UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi);
};
 
#endif
