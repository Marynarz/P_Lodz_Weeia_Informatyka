/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Stol.hpp"
    
Stol::Stol(unsigned const int iloscNog)
{
    no = new Noga[iloscNog];
}
Stol::~Stol()
{
    delete [] no;
}
    void CzyStoiRowno()
    void UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi);
