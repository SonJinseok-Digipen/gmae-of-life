#pragma once
#include"doodle/doodle.hpp"
#include<iostream>
#include<fstream>
#include"Button.h"
#include"cell.h"
#include<vector>
#include<array>
#include"gamemode.h"
using namespace doodle;
class editor
{
private:
   

public:
   
    std::vector<sell> maps;
    const int    sell_width=20;
    const int    sell_height=20;
    const int     width_number  = 40;
    const int     height_number = 40;
    const int     sell_number   = width_number * height_number;
    bool                 sell_is_die   = false;
    bool   IsgameStart = false;
    sell          sells[40][40];
    std::string          string1{"hello"};
    Button               button1{700,900,string1};
    void   Initialize();
    void                 load();
    void   draw();
    void   update(GameMode&e1);
    friend std::ostream& operator<<(std::ostream& os, editor& s1);
};

std::ofstream& save_data(std::ofstream& os, editor& s1);
