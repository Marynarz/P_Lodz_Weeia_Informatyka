#include <iostream>
#include "Circle.hpp"
#include "Rectangle.hpp"
using namespace std;

main()
{
  Circle kolo(2);
  cout <<kolo.area()<<endl;
  Rectangle prostokat(1,2);
  cout <<prostokat.circumference()<<endl;
  return 0;
}
