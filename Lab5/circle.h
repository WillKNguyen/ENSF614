#ifndef CIRCLE
#define CIRCLE

#include "shape.h"

class Circle: virtual public Shape
{
protected:
    double radius;
    const double PI = 3.1415;
public:
    Circle(double x, double y, double radius, const char* shapeName);
    Circle(const Circle& source);
    Circle& operator= (const Circle& rhs);
    ~Circle();
    double area();
    double perimeter();
    void display(); 
    const double getRadius();
};

#endif