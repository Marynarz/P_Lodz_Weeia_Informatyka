    ////////////////
    ////Marynarz////
    ////////////////
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
    	Trojkat(int xa =0, int ya =0, int xb=0, int yb =0, int xc=0, int yc =0, int px=0, int py=0)
    	{
    		tab[0]=xa;
    		tab[1]=ya;
    		tab[2]=xb;
    		tab[3]=yb;
    		tab[4]=xc;
    		tab[5]=yc;
    		tab[6]=px;
    		tab[7]=py;
    	};
    	void wprowadzanie()		//wczytywanie zmiennych
    	{
    		scanf("%f %f %f %f %f %f %f %f",&tab[0],&tab[1],&tab[2],&tab[3],&tab[4],&tab[5],&tab[6],&tab[7]);
    	};
    	bool koniec()			//sprawdzenie konca
    	{
    		if (tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0 &&tab[4]==0 && tab[5]==0 &&tab[6]==0 && tab[7]==0) return false;
    		else return true;
    	}
    	private:
    	void pola()	//liczenie pol
    	{
    		pol[0]=fabs((((tab[2]-tab[0])*(tab[5]-tab[1]))-((tab[4]-tab[0])*(tab[3]-tab[1])))/2);		//pole calego trojkata
    		pol[1]=fabs((((tab[0]-tab[6])*(tab[3]-tab[7]))-((tab[2]-tab[6])*(tab[1]-tab[7])))/2);		//pole trojkata P12
    		pol[2]=fabs((((tab[2]-tab[6])*(tab[5]-tab[7]))-((tab[4]-tab[6])*(tab[3]-tab[7])))/2);		//pole trojkata P23
    		pol[3]=fabs((((tab[4]-tab[6])*(tab[1]-tab[7]))-((tab[0]-tab[6])*(tab[5]-tab[7])))/2);		//pole trojkata P13
    	};
    	public:
    	char checkthis()	//sprawdzanie
    	{
    		pola();
    		if(pol[0]==(pol[1]+pol[2]+pol[3])&&pol[1]!=0&&pol[2]!=0&&pol[3]!=0) return 'I';
    		if((pol[1]==0 || pol[2]==0 || pol[3]==0) && (pol[0]==(pol[1]+pol[2]+pol[3]))) return 'E';
    		else return 'O';
    	}
    };
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
