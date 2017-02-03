#include "Klawiatura.hpp"
Klawiatura::Klawiatura()
	{
		Kla = new int[101];
		
		for(int i =0; i<101;i++)
			Kla[i]->UstawNumer(i);
	}
Klawiatura::Klawiatura(const Klawiatura &K);
Klawiatura::~Klawiatura()
	{
		delete [] Kla;
	}
void Klawiatura::NacisnijKlawisz(const int numer)
{
	Kla[numer]->Nacisnij();
}