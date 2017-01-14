#include "Parallelogram.hpp"

Parallelogram::Parallelogram(double a, double b, double rad):a(a),b(b),radius(rad)
{}
double Parallelogram::area()
{
  return a*b*sin((radius*3.14)/180);
}
double Parallelogram::circumference()
{
  return 2*(a+b);
}