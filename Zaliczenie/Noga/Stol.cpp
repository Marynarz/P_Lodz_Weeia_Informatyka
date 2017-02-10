/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Stol.hpp"
    
Stol::Stol(unsigned const int iloscNog):iloscNog(iloscNog)
{
    no = new Noga[iloscNog];    //tworzenie tablicy obiektow typu Noga o zadanym rozmiarze
}
Stol::~Stol()
{
    delete [] no;   //kasowanie tablicy obiektow typu Noga
}
void Stol::CzyStoiRowno() const
{
    bool czyRowne=true;     //zmienna logiczna - zlaozenie ze wszystkie nogi sa rowne
    for(int i=0;i<iloscNog-1;i++)
    {
        if(no[i].OdczytajDlugosc()!=no[i+1].OdczytajDlugosc())  //sprawdzamy czy dlogosc nog jest rowna
            czyRowne=false;                                     // jesli nie to ustawiamy false
    }
    
    if(czyRowne)    //wypisywanie
        cout <<"Stoi Prosto!"<<endl;
    else
        cout <<"Stoi Krzywo!"<<endl;
}
void Stol::UstawDlugoscNogi(unsigned const int ktoraNoga, unsigned const int dlugoscNogi) const
{
    try     //zabezpiecznie jesli uzytkownik stwierdzi ze bedzie pisal poza pamiecia dozwolona
    {
        const char * wyjatek = "BladNog";
        if(ktoraNoga>iloscNog || ktoraNoga<1)   //sprawdzanie czy mozliwa jest operacja
            throw wyjatek;  //jelsi nie to wywalamy EXCEPTION, operacja nie zostanie wykonana
    
        no[ktoraNoga-1].UstawDlugosc(dlugoscNogi);
    }
    catch(const char * wyj)//lapiemy nasz EXCEPTION, opisujemy problem
    {
        cout <<"Exception: "<<wyj<<": Podana noga: "<<ktoraNoga<<"; Zakres dopuszczalny: 1-"<<iloscNog<<endl;
    }
}

