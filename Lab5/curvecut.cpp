#include "curveCut.h"
#include "cmath"
#include <iostream>
using namespace std;

CurveCut::CurveCut(double x, double y, double sidea, double sideb, double radius, const char* shapeName):
Shape(x,y, shapeName), Circle(x,y,radius,shapeName), Rectangle(x,y,sidea, sideb, shapeName){
    if (radius >= side_a || radius >= side_b)
    {
        cout << "Radius cannot be larger than width or length";
        exit(1);
    }
}

double CurveCut::area(){
    return (Rectangle::area() - Circle::area()/4);
}

double CurveCut::perimeter(){
    return (Rectangle::perimeter() - 2*getRadius() + Circle::perimeter()/4);
}

void CurveCut::display(){
    cout << "CurveCut name: " << getName() << endl;
    printf("X-coordinate: %.2f\n", origin.getX());
    printf("Y-coordinate: %.2f\n", origin.getY());
    cout << "Width: " << getSideA() << endl;
    cout << "Length: " << getSideB() << endl;
    cout << "Radius: " << getRadius() << endl;
}