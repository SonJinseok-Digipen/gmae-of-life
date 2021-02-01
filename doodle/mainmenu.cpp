#include "mainmenu.h"
void mainmenu::update(GameMode&g1) 
{ 
    if (button1.isclicked())
    {
        g1 = GameMode::game;
    }
    if (button2.isclicked())
    {
        g1 = GameMode::howtoplay;
    }
    if (button3.isclicked())
    {
        g1 = GameMode::edit;
    }

}


void mainmenu::draw() 
{ 
	button1.draw();
    button2.draw();
    button3.draw();

}