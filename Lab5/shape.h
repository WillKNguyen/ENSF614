// point.h
// ENSF 614 Lab 5 Exercise A

#ifndef SHAPE
#define SHAPE

#include "point.h"

class Shape
{
protected:
    Point origin;
    char* shapeName;

public:
    Shape(double x, double y, const char* shapeName);
    ~Shape();
    Shape(const Shape& source);
    Shape& operator= (const Shape& rhs);
    const Point& getOrigin() const;
    const char* getName();
    virtual void display();
    double distance(Shape& other);
    static double distance(Shape& the_shape, Shape& other);
    void move (double dx, double dy);
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

#endif