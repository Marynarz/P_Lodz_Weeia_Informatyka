#ifndef Klawiatura_hpp
#define Klawiatura_hpp

#include <iostream>
#include "Klawisz.hpp"

using namespace std;

class Klawiatura
{
	private:
	const Klawisz *Kla;
	
	public:
	Klawiatura();
	Klawiatura(const Klawiatura &K);
	~Klawiatura();
	void NacisnijKlawisz(const int numer);
};


#endif