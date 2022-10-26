#ifndef SQUARE
#define SQUARE

#include "shape.h"

class Square: virtual public Shape
{
protected:
    double side_a;
public:
    Square(double x, double y, double side, const char* shapeName);
    Square(const Square& source);
    Square& operator=(const Square& rhs);
    ~Square();
    double area();
    double perimeter();
    const double getSide();
    void display();
};

#endif