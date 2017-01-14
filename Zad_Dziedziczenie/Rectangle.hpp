#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Parallelogram.hpp"

class Rectangle : public Parallelogram
{
private:
  double a;
  double b;
public:
  Rectangle(double a=0, double b=0);
  virtual double area();
};

#endif