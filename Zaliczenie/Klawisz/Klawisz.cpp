// /* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Klawisz.hpp"
Klawisz::Klawisz(int numer):numer(numer)
{}
void Klawisz::Nacisnij()
{
	cout <<numer<<endl;
}
void Klawisz::UstawNumer(int num)
{
	numer = num;
}
int Klawisz::OdczytajNumer()
{
	return numer;
}
