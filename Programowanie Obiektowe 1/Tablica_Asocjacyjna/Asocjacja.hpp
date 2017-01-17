#ifndef Asocjacja_hpp
#define Asocjacja_hpp

#include <iostream>
#include <string.h>

using namespace std;

class Asocjacja
{
private:
  struct list{
    list *next;
    char* key;
    double value;
  };
  list *head;
public:
  Asocjacja(char *key);
  Asocjacja(const Asocjacja &prev);
  ~Asocjacja();
  void insert(const char* key, double value);
  void clear();
  void find(char* key) const;
};

#endif
