#include "Circle.hpp"
#define PIi 3.14

Circle::Circle(const double rad):radius(rad)
{}
double Circle::area()
{
  return PIi * radius * radius;
}
double Circle::circumference()
{
  return PIi * 2 *radius;
}