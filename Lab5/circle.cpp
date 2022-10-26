#include "circle.h"
#include "cmath"
#include <iostream>
using namespace std;

Circle::Circle(double x, double y, double radius, const char* shapeName):
Shape(x,y,shapeName), radius(radius){}

Circle::Circle(const Circle& source):Shape(source), radius(source.radius){}

Circle& Circle::operator=(const Circle& rhs){
    if (this != &rhs)
    {
        Shape::operator=(rhs);
        radius = rhs.radius;
    }
    return *this;
}

Circle::~Circle(){}

const double Circle::getRadius(){
    return radius;
}

double Circle::area(){
    return PI*pow(radius,2);
}

double Circle::perimeter(){
    return 2*PI*radius;
}

void Circle::display(){
    cout << "Circle name: " << getName() << endl;
    printf("X-coordinate: %.2f\n", origin.getX());
    printf("Y-coordinate: %.2f\n", origin.getY());
    cout << "Radius: " << getRadius() << endl;
    printf("Area: %.2f\n", area());
    printf("Perimeter: %.2f\n", perimeter());
}