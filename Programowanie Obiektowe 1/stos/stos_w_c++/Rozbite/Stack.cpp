#include "Stack.hpp"
  
  Stack::Stack()
  {
      rozmiar = ROZM;
      miejsce = -1;
      addres = new int[rozmiar];
      cout <<"Tworzenie"<<endl;
  }
  Stack::~Stack()
  {
    cout <<"Kasowanie"<<endl;
    delete [] addres;
  }
  void Stack::push(int element)
  {
    if(miejsce >= (rozmiar-1))
        {
            realock();
        }
    miejsce++;
    addres[miejsce] = element;
    cout <<"-----DODAWANIE ELEMENTU : "<<element<<"-----"<<endl;
  }
  int Stack::pop()
  {
    cout <<"+++POP+++"<<endl;
    miejsce--;
    return addres[miejsce+1];
  }
  void Stack::clear()
  {
    cout <<"---CLEAR---"<<endl;
    miejsce =-1;
  }
  bool Stack::isEmpty()
  {
    if(miejsce >=0)
      return false;
    
    return true;
  }
  void Stack::realock()
  {
    int *temp;
    rozmiar *=2;
    temp = new int[rozmiar];
    for (int i =0;i<rozmiar/2;i++)
      temp[i]=addres[i];
    delete [] addres;
    
    addres = temp;
  }
