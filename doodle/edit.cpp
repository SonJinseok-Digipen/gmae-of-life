#include "edit.h"
void editor::Initialize() 
{
    std::cout << "File initalize" << std::endl;
           double posy = 0;
           for (int j = 0; j < height_number; j++)
           {
               double posx = 0;
               for (int i = 0; i < width_number; i++)
               {
                   bool temp_data=false;
                   sell temp_sell{posx, posy, temp_data};
                   sells[j][i] = temp_sell;
                   posx = posx + sell_width;

               }
               posy = posy + sell_height;
           }
           
 }


void editor::load()
{ 
    std::cout << "File load" << std::endl;
    std::ifstream ifs{"result1.txt"};
    bool           temp;
    while (ifs>>temp)
    {
        double posy = 0;
        for (int j = 0; j < height_number; j++)
        {
            double posx = 0;
            for (int i = 0; i < width_number; i++)
            {
                ifs >> temp;
                sell temp_sell{posx, posy, temp};
                sells[j][i] = temp_sell;
                posx        = posx + sell_width;
            }
            posy = posy + sell_height;
        }



    }
    ifs.close();

}


           
   
    
    
    
   
    




void editor::update(GameMode&e1)
{
    double mouseX = get_mouse_x();
    double mouseY = get_mouse_y();
    for (int j = 0; j < height_number; j++)
    {
        for (int i = 0; i < width_number; i++)
        {

            if (MouseIsPressed&&mouseX>sells[j][i].posx && mouseX<sells[j][i].posx+sell_width && mouseY>sells[j][i].posy && mouseY<sells[j][i].posy+sell_height)
            {
                sells[j][i].isdie = 1;
            }
        }
       
    }
    if(button1.isclicked())
    {
        e1 = GameMode::mainmenu;
    }
  

}


void editor::draw() 
{
    for (int j = 0; j < height_number; j++)
    {
        for (int i = 0; i < width_number; i++)
        {
            push_settings();
            if(sells[j][i].isdie==1)
            {
                set_fill_color(0);
            }

            if (sells[j][i].isdie==0)
            {
                set_fill_color(255);
            }

            draw_rectangle(sells[j][i].posx, sells[j][i].posy, sell_width, sell_height);
        }
       
    }
    button1.draw();
}

std::ostream&  operator<< (std::ostream& os, editor& s1) 
{ 
    for (int i=0; i<s1.maps.size(); i++)
    {
        std::cout << s1.maps[i].posx << " " << s1.maps[i].posy << '\n';
    }
    return os;
}


std::ofstream& save_data(std::ofstream& os, editor& s1)
{
   
    for (int j = 0; j < s1.height_number; j++)
    {
        for (int i = 0; i <s1.width_number; i++)
        {
            
            if (s1.sells[j][i].isdie == false)
            {
                os << '0'<<" ";
            }

            if (s1.sells[j][i].isdie ==true)
            {
                os << '1' << " ";
            }
                      
        }
        os << '\n';
    }

    return os; 
}

