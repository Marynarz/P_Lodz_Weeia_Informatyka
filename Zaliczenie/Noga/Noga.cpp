/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Noga.hpp"

Noga::Noga():dlugosc(0)
{}

void Noga::UstawDlugosc(int dl)
{
    dlugosc = dl;
}
    
int Noga::OdczytajDlugosc()
{
    return dlugosc;
}
