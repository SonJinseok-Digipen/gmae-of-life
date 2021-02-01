#pragma once
#include<string>
#include"doodle/doodle.hpp"
#include<iostream>
using namespace doodle;
class Button
{
private:
    const double posx=0;
    const double posy=0;
    const double width=100;
    const double height=50;
    std::string  label{"click me"};
    bool         mouseIsOver = false;
    bool         mousewaspressed = false;
 public:
    Button() = default;
    Button(double posx, double posy, std::string &s);
    Button(double posx, double posy, double width, double height, std::string& s);
    bool isclicked();
    void draw();
    

};


