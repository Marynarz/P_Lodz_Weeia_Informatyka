//Wojciech Niedzielski
//
//COMPLEX number in C++
#include <iostream>
#include "ComplexC.hpp"

using namespace std;


ostream & operator<<(ostream &s, ComplexC & C)	//ostream do couta
{
    return s<<C.getReal()<<"+"<<C.getImagine()<<"i";
}
int operator*(int a, ComplexC C)
{
  return C.getReal()*a;
}
  
int main()
{
    ComplexC a(1,1);
    ComplexC b(2,1);
        
    cout <<"++++COMPLEX++++"<<endl;
    cout<<a<<endl;
    a.showParams();
    cout<<b<<endl;
    b.showParams();
    cout <<"++++++++++++++"<<endl;
    
        cout <<a<<endl<<b<<endl;
    cout <<"-----DODAWANIE-----"<<endl;
    cout <<"c=a+b:\t";
    ComplexC c = a+b;
    cout <<c<<endl;
    cout <<"a+=b+=c:\t";
    a+=b+=c;
    cout <<a<<endl<<endl;
            
        cout <<a<<endl<<b<<endl<<c<<endl;
    cout <<"-----ODEJMOWANIE-----"<<endl;
    cout <<"c=a-b:\t";
    cout <<c<<endl;
    cout <<"a-=b:\t";
    a-=b;
    cout <<a<<endl<<endl;
    
        cout <<a<<endl<<b<<endl<<c<<endl;
    cout <<"-----MNOZENIE-----"<<endl;
    cout <<"c=a*b:\t";
    c=a*b;
    cout <<c<<endl;
    cout <<"a*=b:\t";
    a*=b;
    cout <<a<<endl;
    a*=10;
    a=10*a;
    cout <<a<<endl<<endl;

    cout <<a<<endl<<b<<endl<<c<<endl;    
    cout <<"-----POROWNANIE-----"<<endl;
    bool czy = a==b;
    cout <<"a==b:\t"<<czy<<endl;
    czy = b==c;
    cout <<"b==c:\t"<<czy<<endl<<endl;
    
    cout <<a<<endl<<b<<endl<<c<<endl;
    cout <<"----DZIELENIE----"<<endl;
    cout <<"c=a/b:\t";
    cout <<c<<endl;
    cout <<"a/=b:\t";
    cout <<a<<endl;
  
  return 0;
}