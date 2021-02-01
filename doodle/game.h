#pragma once
#include"edit.h"
#include"cell.h"
#include"Button.h"
#include"gamemode.h"
#include<string>
class game
{
private:
    std::string game_start{"game start"};
    std::string main_menu{"main menu"};
    std::string game_stop{"game stop"};

    Button button1{800, 600, 200, 50, main_menu};
    Button button2{800, 700, 200, 50, game_start};
    Button button3{800, 800, 200, 50, game_stop};

public:
    sell sells[40][40];
    sell nextboard[40][40];
    int  click_count   = 0;
    bool is_gmae_start = false;
    void update(GameMode&mode,editor&sells);
    void draw(editor&e1);
    int near_sell_number(int, int);
    



};
void sells_copy(sell sells1[40][40],sell sells2[40][40]);
void load_data(game& g1, editor& e1);
void save_data(game& g1, editor& e1);
