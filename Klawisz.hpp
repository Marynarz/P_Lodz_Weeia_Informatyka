#ifndef Klawisz_hpp
#define Klawisz_hpp

#include <iostream>

using namespace std;

class Klawisz
{
	private:
	int numer;
	
	public:
	Klawisz(const int numer = -1);
	void Nacisnij();
	void UstawNumer(int wartosc);
	int OdczytajNumer();
};


#endif
