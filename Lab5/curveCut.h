#ifndef CURVECUT
#define CURVECUT

#include "circle.h"
#include "rectangle.h"

class CurveCut: public Circle, public Rectangle
{
public:
    CurveCut(double x, double y, double sidea, double sideb, double radius, const char* shapeName);
    double area();
    double perimeter();
    void display(); 
};

#endif
