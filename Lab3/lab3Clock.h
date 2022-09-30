// lab3Clock.h
// ENSF 614 Fall 2022 LAB 3 - EXERCISE C
// @author Khoi Nguyen

#include <iostream>
using namespace std;

#ifndef lab3Clock
#define lab3Clock

class Clock {
public:
    Clock ();
    // PROMISES: initializes the Clock object with hour, minute, and time set to 0

    Clock (int seconds);
    // PROMISES: initializes the Clock object by converting the seconds provided 
    // to hour, minute, second
    
    Clock (int hour, int minute, int second);
    // PROMISES: initializes the Clock object with the provided parameters.
    // However, everything will be set to 0 if the provided paramters exceded the constraints

    void set_hour (int hour);

    void set_minute (int minute);

    void set_second (int second);

    int get_hour () const;
    int get_minute () const;
    int get_second () const;

    void increment(); 
    void decrement();

    void add_seconds(int seconds);

private:
    int hour;
    int minute;
    int second;
    int hms_to_sec();
    void sec_to_hms (int seconds);
};

#endif