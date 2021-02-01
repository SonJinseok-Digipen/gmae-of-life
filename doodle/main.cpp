#include <doodle/doodle.hpp>
#include"sketch.h"
#include"Button.h"
#include<fstream>
#include"gamemode.h"
using namespace doodle;
sketch sketch1;
std::ofstream output;
GameMode      current_sence = GameMode::game;
int main(void)
{
    sketch1.setup(); // edit mode
    sketch1.update();
    return 0;
}

void on_key_released(KeyboardButtons button)
{
    if (button == KeyboardButtons::Escape)
    {
         close_window();
    }
}



