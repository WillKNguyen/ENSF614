#include "point.h"
#include <cmath>
#include <iostream>
using namespace std;

Point::Point(double xcoord, double ycoord): x(xcoord), y(ycoord){
    id = counter() + 1000;
    activePoints += 1;
    totalPoints += 1;
}

Point::Point(const Point& source): x(source.x), y(source.y){
    id = counter() + 1000;
    activePoints += 1;
    totalPoints += 1;
}

Point::~Point(){
    activePoints -= 1;
}

Point& Point:: operator= (const Point& rhs){
    if (this != &rhs)
    {
        x = rhs.x;
        y = rhs.y;
        id = rhs.id;
    }
    return *this;
}

const double Point::getX(){
    return x;
}

const double Point::getY(){
    return y;
}

int Point::getID(){
    return id;
}

void Point::display(){
    printf("X-coordinate: %.2f\n", getX());
    printf("Y-coordinate: %.2f\n", getY());
}

int Point::counter(){
    return activePoints;
}

double Point::distance(const Point& other){
    return sqrt(pow(other.x - x, 2.0) + pow(other.y - y, 2.0)); 
}


void Point::setx(double dx){
    x = dx;
}

void Point::sety(double dy){
    y = dy;
}

int Point::activePoints = 0;

int Point::totalPoints = 0;

double Point::distance(const Point& one, const Point& two){
    return sqrt(pow(one.x - two.x, 2.0) 
    + pow(one.y - two.y, 2.0)); 
}