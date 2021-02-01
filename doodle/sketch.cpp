#include "sketch.h"
#include"edit.h"
void sketch::setup()
{
    create_window(1000,1000);
    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    set_rectangle_mode(RectMode::Corner);
    if (!std::filesystem::exists("result1.txt"))
    {
        std::cout << "file not exist" << std::endl;
        editor.Initialize();
    }
    if (std::filesystem::exists("result1.txt"))
    {
        std::cout << "file exist" << std::endl;
        editor.load();
    }

    
}

void sketch::update() 
{
    GameMode      CurrentMode = GameMode::mainmenu;
    std::ofstream ofs{"result1.txt"};
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        switch (CurrentMode)
        {  
            case GameMode::edit:
            editor.update(CurrentMode);
            editor.draw();
             break;

            case GameMode::mainmenu: 
            mainmenu.update(CurrentMode);
            mainmenu.draw();
            break;

            case GameMode::howtoplay:
            break;

            case GameMode::game: 
            //game.load(editor,loop_counter);
            load_data(game, editor);
            game.update(CurrentMode,editor);
            game.draw(editor);
            save_data(game, editor);
            break;




        }
              
        
    }
    save_data(ofs, editor);
    
}