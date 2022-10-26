// point.h
// ENSF 614 Lab 5 Exercise A

#ifndef POINT
#define POINT

class Point {
private:
    double x;
    double y;
    int id;
public:
    static int activePoints;
    static int totalPoints;
    Point(double x, double y);
    Point(const Point& source);
    Point& operator= (const Point& rhs);
    ~Point();
    void display();
    int counter();

    double distance(const Point& other);
    static double distance(const Point& one, const Point& two);

    const double getX();
    const double getY();
    int getID(); 
    void setx(double dx);
    void sety(double dy);
};


#endif