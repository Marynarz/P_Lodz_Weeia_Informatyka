#include "Asocjacja.hpp"
Asocjacja::Asocjacja(char* key, double value)
{
  head->next = NULL;
  head->key = key;
  head->value = value;
}
