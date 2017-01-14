#ifndef Circle_hpp
#define Circle_hpp

#include "Shapes.hpp"

class Circle : public Shapes
{
private:
  double radius;
public:
  Circle(double rad=0);
  virtual double area();
  virtual double circumference();
};

#endif