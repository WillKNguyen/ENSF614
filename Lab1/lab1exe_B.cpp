/*
 *  lab1exe_B.cpp
 *  ENSF 614 Lab 1, exercise B
 *  Created by Mahmood Moussavi
 *  Completed by: Khoi Nguyen
 */

#include <iostream>
#include <cmath>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    if(!cin)  // means if cin failed to read
    {
        cout << "Invlid input. Bye...\n";
        exit(1);
    }
    
    while (velocity < 0 )
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin)
        {
            cout << "Invalid input. Bye...";
            exit(1);
        }
    }

    create_table(velocity);
    
    return 0;
}

//Converting degree value to radian
double degree_to_radian(double degree)
{
    return degree * PI/180;
}

//Calculating the projectile travel time using angle and initial velocity
double Projectile_travel_time(double angle, double v)
{
    return 2*v*sin(angle)/G;
}

//Calculating the projectile travel distance using angle and initial velocity
double Projectile_travel_distance(double angle, double v)
{
    return pow(v,2)*sin(2*angle)/G;
}

//Printing a table containing the angle of launch and corresponding time and distance travelled associated with the initial velocity
void create_table (double v)
{
    printf("Angle (deg) \tt (sec) \td (m)\n");
    double angle;
    double distance;
    double time;
    for (int degree = 0; degree <= 90; degree+=5)
    {
        angle = degree_to_radian(degree);
        time = Projectile_travel_time(angle, v);
        distance = Projectile_travel_distance(angle, v);
        printf("%i\t%f\t%f\n", degree, time, distance);
    }
    
}
