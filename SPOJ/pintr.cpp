    ////////////////
    ////Marynarz////
    ////////////////
    #include <iostream>
    #include <stdio.h>
    #include <math.h>
    #include <vector>
    #include "Trojkat.hpp"

    using namespace std;

    int main() {
    	Trojkat t;
    	bool dupa = true;
    	vector <char> tab;
    	while(dupa)			//petla glowna
    	{
    	t.wprowadzanie();
    	dupa = t.koniec();	//sprawdzanie czy nie bylo konca
    	if(dupa) tab.push_back(t.checkthis());
    	};
    	for(int i=0; i<tab.size();i++) printf("%c\n",tab[i]); //wyswietlanie zawartosci wektora
    	return 0;
    }
