#include "rectangle.h"
#include "cmath"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* shapeName):
Shape(x,y, shapeName), Square(x,y, side_a,shapeName), side_b(side_b){}

Rectangle::Rectangle(const Rectangle& source):Shape(source), Square(source), side_b(source.side_b){}

Rectangle& Rectangle::operator=(const Rectangle& rhs){
    if (this != &rhs)
    {
        Shape::operator=(rhs);
        Square::operator=(rhs);
        side_b = rhs.side_b;
    }
    return *this;
}

Rectangle::~Rectangle(){}

double Rectangle::area(){
    return side_a*side_b;
}

double Rectangle::perimeter(){
    return 2*side_a + 2*side_b;
}

const double Rectangle::getSideA(){
    return side_a;
}

const double Rectangle::getSideB(){
    return side_b;
}

void Rectangle::set_side_a(double a){side_a = a;}

void Rectangle::set_side_b(double b){side_b = b;}

void Rectangle::display(){
    cout << "Rectangle name: " << getName() << endl;
    printf("X-coordinate: %.2f\n", origin.getX());
    printf("Y-coordinate: %.2f\n", origin.getY());
    cout << "Side a: " << getSideA() << endl;
    cout << "Side b: " << getSideB() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}