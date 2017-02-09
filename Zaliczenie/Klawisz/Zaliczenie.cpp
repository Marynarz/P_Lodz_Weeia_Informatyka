#include <iostream>
#include "Klawiatura.hpp"

using namespace std;

int main()
{
    Klawiatura kla;
    for(int i=0; i<101; i++)
        kla.NacisnijKlawisz(i);
    
    Klawisz klawi(2);
    klawi.Nacisnij();
    return 0;
}
