#include "./include/project.h"
#include <stdbool.h>

#define PIOB_PER  (volatile unsigned int*)0xfffff400
#define PIOB_OER  (volatile unsigned int*)0xfffff410
#define PIOB_SODR (volatile unsigned int*)0xfffff430
#define PIOB_CODR (volatile unsigned int*)0xfffff434

#define PIOC_PER  (volatile unsigned int*)0xfffff600
#define PIOC_OER  (volatile unsigned int*)0xfffff610
#define PIOC_ODR  (volatile unsigned int*)0xfffff614
#define PIOC_SODR (volatile unsigned int*)0xfffff630
#define PIOC_CODR (volatile unsigned int*)0xfffff634
//Pin Data Status Register
#define PIOC_PDSR (volatile unsigned int*)0xfffff63C
//Setting peripheral clock
#define PMC_PCER  (volatile unsigned int*)0xfffffC10

#define Q1 1<<29
#define Q2 1<<28
#define Q3 1<<30

#define A 1<<25
#define B 1<<24
#define C 1<<22
#define D 1<<21
#define E 1<<20
#define F 1<<27
#define G 1<<26
#define DOT 1<<23


void dbgu_print_ascii (const char *buffer)
{

}

void initPiob()
{
  *PIOB_PER = Q1|Q2|Q3|A|B|C|D|E|F|G|DOT;
  *PIOB_OER = Q1|Q2|Q3|A|B|C|D|E|F|G|DOT;
  *PIOB_CODR= Q1|Q2;
}
void wyswietlaczCzesc(bool ktora)
{
  if(ktora)	//true to lewa
  {
    *PIOB_CODR = Q2;
    *PIOB_SODR = Q3;
  }
  else
  {
    *PIOB_CODR = Q3;
    *PIOB_SODR = Q2;
  }
}

void cyfry(short cyfra,bool strona){
	czyszczenie(); 
	wyswietlaczCzesc(strona);
	switch(cyfra)
	{
		case 0: *PIOB_SODR = A|B|C|D|E|F; break;
		case 1: *PIOB_SODR = B|C; 		  break;
		case 2: *PIOB_SODR = A|B|G|E|D;   break;
		case 3: *PIOB_SODR = A|B|C|D|G;   break; 
		case 4: *PIOB_SODR = B|C|G|F; 	  break;
		case 5: *PIOB_SODR = A|C|D|F|G;   break;
		case 6: *PIOB_SODR = A|C|D|E|F|G; break;
		case 7: *PIOB_SODR = A|B|C; 	  break;
		case 8: *PIOB_SODR = A|B|C|D|E|F|G; break;
		case 9: *PIOB_SODR = A|B|C|D|F|G; break;
	}
}
void czyszczenie(void){
	*PIOB_CODR = A|B|C|D|E|F|G|DOT;
}

int main(void)
{
  initPiob();

  return 0;
}
