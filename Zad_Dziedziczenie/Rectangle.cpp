#include "Rectangle.hpp"

Rectangle::Rectangle(double a, double b):a(a),b(b),Parallelogram(a,b,0)
{}
double Rectangle::area()
{
  return a*b;
}