//
//Wojciech Niedzielski
//
//Stack in C
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define ROZM 2

struct Stack{
  int *addres;
  int rozmiar;
  int miejsce;
};

void init(struct Stack* s)
{
    s->rozmiar = ROZM;
    s->miejsce = -1;
    s->addres = (int*) malloc(sizeof(int)*s->rozmiar);
    printf("Tworzenie\n");
}
void destroy(struct Stack* s)
{
  printf("Kasowanie\n");
  free(s->addres);
}
void push(struct Stack* s, int element)
{
  if(s->miejsce >= (s->rozmiar-1))
  {
    s->rozmiar *= 2;
    s->addres = (int*) realloc(s->addres,s->rozmiar*sizeof(int));
  }
  s->miejsce++;
  s->addres[s->miejsce] = element;
  printf("-----DODAWANIE ELEMENTU : %d-----\n",element);
}
int pop(struct Stack* s)
{
    printf("+++POP+++\n");
    int score = s->addres[s->miejsce];
    s->miejsce--;
    return score;
}
void clear(struct Stack* s)
{
  printf("---CLEAR---");
  int i =0;
  s->miejsce =-1;
  for(i = 0 ; i<s->rozmiar;i++)
    s->addres[i] =0;
}
bool isEmpty(struct Stack* s)
{
    if(s->miejsce >=0)
      return false;
    
  return true;
}

int main()
{
  struct Stack s;
  int i=0;
  init(&s);
  
  for(i=0; i<25;i++)
    push(&s,i);
  clear(&s);
  while(!isEmpty(&s))
  {
    printf("%d\n",pop(&s));
  }
    
  for(i=0; i<25;i++)
    push(&s,i*4);
  
  while(!isEmpty(&s))
  {
    printf("%d\n",pop(&s));
  }

  destroy(&s);
  return 0;
}
