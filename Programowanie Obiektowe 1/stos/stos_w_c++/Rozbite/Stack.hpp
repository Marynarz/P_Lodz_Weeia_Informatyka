#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#define ROZM 2

using namespace std;

class Stack
{
  int *addres;
  int rozmiar;
  int miejsce;

public:
  Stack();
  ~Stack();
  void push(int element);
  int pop();
  void clear();
  bool isEmpty();
private:
  void realock();  
};

#endif
