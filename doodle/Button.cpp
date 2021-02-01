#include"Button.h"
Button::Button(double posx, double posy, std::string &s) : posx{posx}, posy{posy}, label{s} {};
Button::Button(double posx, double posy, double width, double height, std::string& s)
    : posx{posx}, posy{posy}, width{width}, height{height}, label{s} {};
//생성자 만들기 


bool Button::isclicked() 
{
    const double left    = posx;
    const double rigth  = posx + width;
    const double top     = posy;
    const double bottom  = posy + height;
	double mousex = get_mouse_x();
    double mousey = get_mouse_y();
    bool         withinX = mousex > left && mousex < rigth;
    bool         withinY = mousey > top && mousey < bottom;
    mouseIsOver          = withinX && withinY;
    bool clicked_it      = this->mouseIsOver&&this->mousewaspressed &&!MouseIsPressed;
    this->mousewaspressed = MouseIsPressed; 
    return clicked_it;
     
      
}


void Button::draw() 
{ 
    push_settings();
    set_font_size(20);
    draw_rectangle(posx, posy, width, height);
    draw_text(label, posx+50, posy+50);
    //draw_text(label, posx, posy);
    pop_settings();
     
}

