#include "Klawisz.hpp"
Klawisz::Klawisz(const int numer):numer(numer)
{}
void Klawisz::Nacisnij()
{
	cout <<numer;
}
void Klawisz::UstawNumer(int num)
{
	numer = num;
}
int Klawisz::OdczytajNumer()
{
	return numer;
}
