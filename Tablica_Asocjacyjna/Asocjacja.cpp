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
