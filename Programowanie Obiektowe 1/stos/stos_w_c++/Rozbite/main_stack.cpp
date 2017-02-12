//Wojciech Niedzielski
//
//Stack in C++
#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
  Stack stosik;
  
  for(int i=0; i<25;i++)
    stosik.push(i);
  
  stosik.clear();
  
  while(!stosik.isEmpty())
  {
    cout <<stosik.pop()<<endl;
  }
    
  for(int i=0; i<25;i++)
    stosik.push(i*4);
  
  while(!stosik.isEmpty())
  {
    cout <<stosik.pop()<<endl;
  }
  return 0;
}
