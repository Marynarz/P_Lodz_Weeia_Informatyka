/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#ifndef Klawiatura_hpp
#define Klawiatura_hpp

#include <iostream>
#include "Klawisz.hpp"

using namespace std;

class Klawiatura
{
	Klawisz *kla;
	
	public:
	Klawiatura();
	Klawiatura(const Klawiatura &K);
	~Klawiatura();
	void NacisnijKlawisz(int numer);
    Klawiatura & operator=(const Klawiatura K);
};


#endif
