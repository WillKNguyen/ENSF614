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
    // However, everything will be set to 0 if any of the provided parameters
    // exceeded their accepted range

    void set_hour (int hour);
    // PROMISES: set the hour part to the provided value if it is within the accepted range

    void set_minute (int minute);
    // PROMISES: set the minute part to the provided value if it is within the accepted range

    void set_second (int second);
    // PROMISES: set the second part to the provided value if it is within the accepted range

    int get_hour () const;
    // PROMISES: returns the hour part of the clock

    int get_minute () const;
    // PROMISES: returns the minute part of the clock

    int get_second () const;
    // PROMISES: returns the second part of the clock

    void increment(); 
    // PROMISES: increases the clock by 1 second increment

    void decrement();
    // PROMISES: decreases the clock by 1 second increment

    void add_seconds(int seconds);
    // PROMISES: increases the clock by the provided seconds

private:
    int hour;   // the hour component
    int minute; // the minute component
    int second; // the second component
    int hms_to_sec();
    // PROMISES: this helper function returns the current clock time
    // to total seconds
    void sec_to_hms (int seconds);
    // PROMISES: this helper function converts the provided number of seconds
    // to clock time
};

#endif