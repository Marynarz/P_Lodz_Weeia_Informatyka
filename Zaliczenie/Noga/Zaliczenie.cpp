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
    s1.UstawDlugoscNogi(3,6);
    cout <<s1.CzyStoiRowno()<<endl;
    s1.UstawDlugoscNogi(1,5);
    cout <<s1.CzyStoiRowno()<<endl;
    
    return 0;
}

/*
 *VALGRIND TEST REPORT: PASSED 
 * 
 * 
valgrind ./a.out 
==3777== Memcheck, a memory error detector
==3777== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3777== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==3777== Command: ./a.out
==3777== 
4
1
0
==3777== 
==3777== HEAP SUMMARY:
==3777==     in use at exit: 0 bytes in 0 blocks
==3777==   total heap usage: 3 allocs, 3 frees, 73,740 bytes allocated
==3777== 
==3777== All heap blocks were freed -- no leaks are possible
==3777== 
==3777== For counts of detected and suppressed errors, rerun with: -v
==3777== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

 */
