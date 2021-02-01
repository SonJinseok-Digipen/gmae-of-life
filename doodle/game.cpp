#include "game.h"
void load_data(game &g1,editor& e1)
{
    if (g1.is_gmae_start == false)
    {
        std::memcpy(g1.sells, e1.sells, sizeof(e1.sells));
    }
    
}

void sells_copy(sell sells1[40][40],sell sells2[40][40]) 
{
    for (int j = 0; j <40 ; j++)
    {
        for (int i = 0; i < 40; i++)
        {
            sells2[j][i] = sells1[j][i];
        }
    }
}


int game:: near_sell_number(int height,int width) 
{
   
      int livingNeighbors = 0;
     if (sells[height-1][width-1].isdie==true)
      {
         livingNeighbors++;
      }
      if (sells[height - 1][width].isdie == true)
      {
          livingNeighbors++;
      }
      if (sells[height - 1][width+1].isdie == true)
      {
          livingNeighbors++;
      }
      if (sells[height][width - 1].isdie == true)
      {
          livingNeighbors++;
      }
    
      if (sells[height][width + 1].isdie == true)
      {
          livingNeighbors++;
      }
      if (sells[height + 1][width - 1].isdie == true)
      {
          livingNeighbors++;
      }
      if (sells[height + 1][width].isdie == true)
      {
          livingNeighbors++;
      }
      if (sells[height+1][width + 1].isdie == true)
      {
          livingNeighbors++;
      }
      return livingNeighbors;
     
      
     
}


void game::update(GameMode& mode, editor& e1)
{
    if (button1.isclicked())
    {
        mode          = GameMode::mainmenu;
        is_gmae_start = false;
    }


    if (button2.isclicked())
    {
        is_gmae_start = true;
    }

    if (button3.isclicked())
    {
        is_gmae_start = false;
    }
    if (is_gmae_start)
    {
        sell temp_sells[40][40];
        std::memcpy(temp_sells, sells, sizeof(sells));
        for (int j = 0; j < e1.height_number; j++)
        {
            for (int i = 0; i < e1.width_number; i++)
            {
               

                if (i == 0 || j == 0 || i == 40 || j == 40)
                {
                    temp_sells[j][i].isdie = false;
                }

                else
                {
                    // counting alive neighbouring cells
                     int alive_sell = near_sell_number(j, i);
                    if (sells[j][i].isdie == 1)
                    {
                        if (alive_sell < 2 || alive_sell > 3)
                            temp_sells[j][i].isdie = false; // cell dies due to loneliness or overcrowding
                        else
                           temp_sells[j][i].isdie = true;
                    }

                    else
                    {
                        if (alive_sell == 3)
                            temp_sells[j][i].isdie = true; // birth of a new cell
                        else
                            temp_sells[j][i].isdie = false;
                    }
                }


            }
        }
        std::memcpy(sells, temp_sells, sizeof(temp_sells));

    }
}
    


void game::draw(editor& e1)
{
    for (int j = 0; j < e1.height_number; j++)
    {
        for (int i = 0; i < e1.width_number; i++)
        {
            push_settings();
            if (sells[j][i].isdie == 1)
            {
                set_fill_color(0);
            }

            if (sells[j][i].isdie == 0)
            {
                set_fill_color(255);
            }

            draw_rectangle(sells[j][i].posx, sells[j][i].posy, e1.sell_width, e1.sell_height);
        }
    }


    button1.draw();
    button2.draw();
    button3.draw();
}

void save_data(game& g1, editor& e1) 
{ 
    std::memcpy(e1.sells, g1.sells, sizeof(g1.sells));
}