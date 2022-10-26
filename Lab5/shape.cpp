#include "shape.h"
#include <iostream>
#include <string.h>
using namespace std;

Shape::Shape (double x, double y, const char* name): origin(x,y){
    shapeName = new char[strlen(name)+1];
    for (unsigned int i = 0; i < strlen(name); i++)
    {
        shapeName[i] = name[i];
    }
    shapeName[strlen(name)] = '\0';
}

Shape::Shape(const Shape& source): origin(source.origin){
    shapeName = new char[strlen(source.shapeName)+1];
    for (unsigned int i = 0; i < strlen(source.shapeName); i++)
    {
        shapeName[i] = source.shapeName[i];
    }
    shapeName[strlen(source.shapeName)] = '\0';
}

Shape& Shape:: operator=(const Shape& rhs){
    if (this != &rhs)
    {
        delete shapeName;
        shapeName = new char[strlen(rhs.shapeName)+1];
        for (unsigned int i = 0; i < strlen(rhs.shapeName); i++)
        {
            shapeName[i] = rhs.shapeName[i];
        }
        shapeName[strlen(rhs.shapeName)] = '\0';
        origin = rhs.origin;
    }
    return *this;
}

Shape::~Shape(){
    delete shapeName;
    shapeName = nullptr;
}

const Point& Shape::getOrigin() const{
    return origin;
}

const char* Shape::getName(){
    return shapeName;
}

void Shape::display(){
    cout<< "Shape name: " << shapeName << endl;
    printf("X-coordinate: %.2f\n", origin.getX());
    printf("Y-coordinate: %.2f\n", origin.getY());
}

double Shape::distance(Shape& other){
    return origin.distance(other.getOrigin());
}

double Shape::distance (Shape& the_shape, Shape& other){
    return Point::distance(the_shape.getOrigin(), other.getOrigin());
}

void Shape::move(double dx, double dy){
    origin.setx(dx);
    origin.sety(dy);
}