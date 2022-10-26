#include "square.h"
#include "cmath"
#include <iostream>
using namespace std;

Square::Square(double x, double y, double side, const char* shapeName): 
Shape(x,y, shapeName), side_a(side){}

Square::Square(const Square& source): Shape(source), side_a(source.side_a){} 

Square& Square::operator=(const Square& rhs){
    if (this != &rhs)
    {
        side_a = rhs.side_a;
        Shape::operator=(rhs);
    }

    return *this;
}

Square::~Square(){}

double Square::area(){
    return pow(side_a, 2);
}

double Square::perimeter(){
    return (4*side_a);
}

const double Square::getSide(){
    return side_a; 
}

void Square::display(){
    cout << "Square name: " << shapeName << endl;
    printf("X-coordinate: %.2f\n", origin.getX());
    printf("Y-coordinate: %.2f\n", origin.getY());
    cout << "Side a: " << getSide() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
