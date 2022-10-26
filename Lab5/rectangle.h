#ifndef RECTANGLE
#define RECTANGLE

#include "square.h"

class Rectangle: public Square
{
protected:
    double side_b;
public:
    Rectangle(double x, double y, double side_a, double side_b, const char* shapeName);
    Rectangle(const Rectangle& source);
    Rectangle& operator=(const Rectangle& rhs);
    ~Rectangle();
    double area();
    double perimeter();
    void display(); 
    const double getSideA();
    const double getSideB();
    void set_side_a(double a);
    void set_side_b(double b);
};

#endif