#include <iostream>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
using namespace std;

int main()
{
  vector<Shapes*>shapes;
  
  shapes.push_back(new Circle(0.5));
  shapes.push_back(new Parallelogram(5,2,60));
  shapes.push_back(new Rectangle(5,2));
  for(int i =0; i<shapes.size();i++ )
  {
    cout <<shapes[i]->area()<<endl;
    cout <<shapes[i]->circumference()<<endl;
  }
  
  return 0;
}
