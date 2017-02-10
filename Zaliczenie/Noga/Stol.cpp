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
void Stol::CzyStoiRowno()
{
    bool czyRowne=true;
    for(int i=0;i<iloscNog-1;i++)
    {
        if(no[i].OdczytajDlugosc()!=no[i+1].OdczytajDlugosc())
            czyRowne=false;
    }
    
    if(czyRowne)
        cout <<"Stoi Prosto!"<<endl;
    else
        cout <<"Stoi Krzywo!"<<endl;
}
void Stol::UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi)
{
    try
    {
        const char * wyjatek = "BladNog";
        if(ktoraNoga>iloscNog || ktoraNoga<1)
            throw wyjatek;
    
        no[ktoraNoga-1].UstawDlugosc(dlugoscNogi);
    }
    catch(const char * wyj)
    {
        cout <<"Exception: "<<wyj<<": Podana noga: "<<ktoraNoga<<"; Zakres dopuszczalny: 1-"<<iloscNog<<endl;
    }
}

