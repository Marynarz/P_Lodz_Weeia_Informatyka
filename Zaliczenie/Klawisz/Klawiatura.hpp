#ifndef Klawiatura_hpp
#define Klawiatura_hpp

#include <iostream>
#include "Klawisz.hpp"

using namespace std;

class Klawiatura
{
	private:
	Klawisz *Kla[101];
	
	public:
	Klawiatura();
	//Klawiatura(const Klawiatura &K);
	~Klawiatura();
	void NacisnijKlawisz(int numer);
};


#endif
