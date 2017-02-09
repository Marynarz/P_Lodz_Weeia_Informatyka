/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include "Klawiatura.hpp"
Klawiatura::Klawiatura()
	{
        kla = new Klawisz[101];
        
		for(int i =0; i<101;i++)
			kla[i].UstawNumer(i);
	}
//Klawiatura::Klawiatura(const Klawiatura &K);
Klawiatura::~Klawiatura()
	{
		delete [] kla;
	}
void Klawiatura::NacisnijKlawisz(int numer)
{
	kla[numer].Nacisnij();
}
