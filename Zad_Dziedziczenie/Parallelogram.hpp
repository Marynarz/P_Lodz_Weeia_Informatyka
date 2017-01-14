#ifndef Parallelogram_hpp
#define Parallelogram_hpp

#include "Shapes.hpp"
#include <math.h>

class Parallelogram : public Shapes
{
private:
  double a;
  double b;
  double radius;
  
public:
  Parallelogram(double a=0, double b=0, double rad =0);
  virtual double area();
  virtual double circumference();
};

#endif