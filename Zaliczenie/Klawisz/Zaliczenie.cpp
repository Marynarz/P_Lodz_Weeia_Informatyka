/* GitHUB: MARYNARZ REPO: P_LODZ_WEEIA_INFORMATYKA */
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
    Klawiatura kla1 = kla;
    kla1.NacisnijKlawisz(3);
    return 0;
}

/*

VALGRIND TEST REPORT::

valgrind ./a.out 
==3818== Memcheck, a memory error detector
==3818== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3818== Using Valgrind-3.12.0 and LibVEX; rerun with -h for copyright info
==3818== Command: ./a.out
==3818== 
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
2
==3818== 
==3818== HEAP SUMMARY:
==3818==     in use at exit: 0 bytes in 0 blocks
==3818==   total heap usage: 3 allocs, 3 frees, 74,132 bytes allocated
==3818== 
==3818== All heap blocks were freed -- no leaks are possible
==3818== 
==3818== For counts of detected and suppressed errors, rerun with: -v
==3818== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/
