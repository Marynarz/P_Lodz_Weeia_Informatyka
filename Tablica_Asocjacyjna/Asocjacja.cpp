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
Asocjacja::~Asocjacja()
{
    head->key = NULL;
}

void Asocjacja::insert(const char *k, int value)
{
        char *key = new char[strlen (k) + 1];
        char mark;

        for(int i =0; i<k+1;i++)
        {
                mark = *(k+i);
                *(key+i) = mark;
        }
        *(key+strlen(k)+1) = '\0';
}

void Asocjacja::clear()
{
    while(head)
    {
        list *t = head ->next;
        delete head;
        head = t;
    }
}
