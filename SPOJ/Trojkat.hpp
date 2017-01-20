#ifndef TROJKAT_HPP
#define TROJKAT_HPP

    #include <iostream>
    #include <stdio.h>
    #include <math.h>
    #include <vector>

    using namespace std;
class Trojkat
    {
    	float tab[8];				//dane wejsciowe (x1 y1 x2 y2 x3 y3 xp yp)
    	float pol[4];			//pola 0 - ogolne 1,3 - kolejnych trojkatow
    	public:
    	Trojkat(int xa =0, int ya =0, int xb=0, int yb =0, int xc=0, int yc =0, int px=0, int py=0);
    	void wprowadzanie();		//wczytywanie zmiennych
    	bool koniec();			//sprawdzenie konca
    	private:
    	void pola();	//liczenie pol
    	public:
    	char checkthis();	//sprawdzanie
    };

#endif // TROJKAT_HPP
