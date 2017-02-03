#include "Klawiatura.hpp"
Klawiatura::Klawiatura()
	{
		for(int i =0; i<101;i++)
			Kla[i] = new Klawisz(i);
	}
//Klawiatura::Klawiatura(const Klawiatura &K);
Klawiatura::~Klawiatura()
	{
		delete [] Kla;
	}
void Klawiatura::NacisnijKlawisz(int numer)
{
	Kla[numer]->Nacisnij();
}
