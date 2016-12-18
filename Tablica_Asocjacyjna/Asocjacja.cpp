#include "Asocjacja.hpp"
Asocjacja::Asocjacja()
{

}
Asocjacja::Asocjacja(const Asocjacja & prev)
{
  head->prev = NULL;
}
