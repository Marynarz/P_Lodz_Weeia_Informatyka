/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
#include <iostream>
#include "Stol.hpp"

using namespace std;

int main()
{
    Noga n1;
    n1.UstawDlugosc(4);
    cout <<n1.OdczytajDlugosc()<<endl;
    
    Stol s1(3);
    s1.UstawDlugoscNogi(1,6);
    s1.UstawDlugoscNogi(6,6);
    s1.UstawDlugoscNogi(2,6);
    s1.UstawDlugoscNogi(3,6);
    s1.CzyStoiRowno();
    s1.UstawDlugoscNogi(1,5);
    s1.CzyStoiRowno();
    
    return 0;
}

/*
 *VALGRIND TEST REPORT: PASSED 
 * 
 * 
valgrind ./a.out 
==3592== Memcheck, a memory error detector
==3592== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3592== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==3592== Command: ./a.out
==3592== 
4
Exception: BladNog: Podana noga: 6; Zakres dopuszczalny: 1-3
Stoi Prosto!
Stoi Krzywo!
==3592== 
==3592== HEAP SUMMARY:
==3592==     in use at exit: 0 bytes in 0 blocks
==3592==   total heap usage: 4 allocs, 4 frees, 73,876 bytes allocated
==3592== 
==3592== All heap blocks were freed -- no leaks are possible
==3592== 
==3592== For counts of detected and suppressed errors, rerun with: -v
==3592== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


 */
