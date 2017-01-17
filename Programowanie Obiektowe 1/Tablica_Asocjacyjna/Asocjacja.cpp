#include "Asocjacja.hpp"
Asocjacja::Asocjacja(char *key)
{
    head->next=NULL;
    head->key = key;
}
Asocjacja::Asocjacja(const Asocjacja & prev)
{
    head->next = NULL;
    if (prev.head->key == NULL)
        head->key = NULL;
    else
    {
        head->key = new char[strlen (prev.head->key) + 1];
        strcpy (head->key, prev.head->key);
    }

    head->value=prev.head->value;


}
Asocjacja::~Asocjacja()//na to nie mam jeszcze pomyslu ;(
{
    head->key = NULL;
}

void Asocjacja::insert(const char *k, int value)
{
        char *key = new char[strlen (k) + 1]; //tworzenie nowego klucza
        char mark;

        for(int i =0; i<k+1;i++)
        {
                mark = *(k+i);      //ciekawe czy zadziala
                *(key+i) = mark;
        }
        *(key+strlen(k)+1) = '\0';  //dopisywanie znaku nowej linii
}

void Asocjacja::clear()  //funkcja clear - do czyszczenia tablicy
{
    while(head)     //dzialaj poki head nie jest nullem
    {
        list *t = head ->next;  //utworzenie tymczasowej strukturki
        delete head;    //usuniecie stukturki
        head = t;   //przypisanie nowej glowy
    }
}
