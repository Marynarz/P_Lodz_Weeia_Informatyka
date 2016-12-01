//Wojciech Niedzielski
//
//Stack in C++
#include <iostream>
#define ROZM 2

using namespace std;

class StackC
{
  int *addres;
  int rozmiar;
  int miejsce;

public:
  StackC()
  {
      rozmiar = ROZM;
      miejsce = -1;
      addres = new int[rozmiar];
      cout <<"Tworzenie"<<endl;
  }
  ~StackC()
  {
    cout <<"Kasowanie"<<endl;
    delete [] addres;
  }
  void push(int element)
  {
    if(miejsce >= (rozmiar-1))
  {
    realock();
  }
    miejsce++;
    addres[miejsce] = element;
    cout <<"-----DODAWANIE ELEMENTU : "<<element<<"-----"<<endl;
  }
  int pop()
  {
    cout <<"+++POP+++"<<endl;
    int score = addres[miejsce];
    miejsce--;
    return score;
  }
  void clear()
  {
    cout <<"---CLEAR---"<<endl;
    miejsce =-1;
  }
  bool isEmpty()
  {
    if(miejsce >=0)
      return false;
    
    return true;
  }
  private:
  void realock()
  {
    int *temp;
    rozmiar *=2;
    temp = new int[rozmiar];
    for (int i =0;i<rozmiar/2;i++)
      temp[i]=addres[i];
    delete [] addres;
    
    addres = temp;
  }
    
};

int main()
{
  StackC stosik;
  
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
