// lab3Clock.cpp
// ENSF 614 Fall 2022 LAB 3 - EXERCISE C
// @author Khoi Nguyen

#include "lab3Clock.h"

Clock::Clock(): hour(0), minute(0), second(0){

}

Clock::Clock(int seconds){
    if (seconds < 0)
    {
        this->set_hour(0);
        this->set_minute(0);
        this->set_second(0);
    }
    else
    {
        sec_to_hms(seconds);
    }
}

Clock::Clock(int h, int m, int s){
    if ((h < 24 && h >= 0) && (m < 60 && m >= 0) && (s < 60 && s >= 0))
    {
        this->set_hour(h);
        this->set_minute(m);
        this->set_second(s);
    }
    else
    {
        this->set_hour(0);
        this->set_minute(0);
        this->set_second(0);
    }
}

void Clock::set_hour(int h){
    if (h < 24 && h >= 0)
    {
        this->hour = h;
    }
}

void Clock::set_minute(int m){
    if (m < 60 && m >= 0)
    {
        this->minute = m;
    }
}

void Clock::set_second(int s){
    if (s < 60 && s >= 0)
    {
        this->second = s;
    }
}

int Clock::get_hour() const{
    return hour;
}

int Clock::get_minute() const{
    return minute;
}

int Clock::get_second() const{
    return second;
}

void Clock::increment(){
    sec_to_hms(hms_to_sec() + 1);
}

void Clock::decrement(){
    int temp = hms_to_sec() - 1;
    if (temp < 0)
    {
        temp += 86400;
    }
    sec_to_hms(temp);
}

void Clock::add_seconds(int seconds){
    sec_to_hms(hms_to_sec() + seconds);
}

void Clock::sec_to_hms(int s){
    int to_h = s/3600;
    int to_m = (s - to_h*3600)/60;
    int to_s = s - to_h*3600 - to_m*60;
    while (to_h >= 24)
    {
        to_h -= 24;
    }    
    this->hour = to_h;
    this->minute = to_m;
    this->second = to_s;
}

int Clock::hms_to_sec(){
    return (hour*3600 + minute*60 + second);
}
