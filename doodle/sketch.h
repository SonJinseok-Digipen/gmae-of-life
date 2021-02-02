#pragma once
#include"Button.h"
#include<iostream>
#include"doodle/doodle.hpp"
#include"edit.h"
#include"gamemode.h"
#include"game.h"
#include"mainmenu.h"
#include<fstream>

using namespace doodle;
class sketch
{
public:
    
    editor editor;
    mainmenu mainmenu;
    game     game;
    void setup();
    void update();
    
};


