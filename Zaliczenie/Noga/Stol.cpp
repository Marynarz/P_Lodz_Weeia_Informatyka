/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Stol.hpp"
    
Stol::Stol(unsigned const int iloscNog):iloscNog(iloscNog)
{
    no = new Noga[iloscNog];
}
Stol::~Stol()
{
    delete [] no;
}
bool Stol::CzyStoiRowno()
{
    for(int i=0;i<iloscNog-1;i++)
    {
        if(no[i].OdczytajDlugosc()!=no[i+1].OdczytajDlugosc())
        {
            return false;
        }
        
    }
    return true;
}
void Stol::UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi)
{
    no[ktoraNoga-1].UstawDlugosc(dlugoscNogi);
}

