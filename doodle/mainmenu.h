#pragma once
#include<string>
#include"Button.h"
#include"gamemode.h"
class mainmenu
{
private:
    std::string game_start{"game start"};
    std::string how_to_play{"how to play"};
    std::string edit{"edit"};

    Button button1{450,400,200,50,game_start};
    Button button2{450,500,200,50, how_to_play};
    Button button3{450,600,200,50, edit};

public:
    void update(GameMode& g1);
    void draw();


};
