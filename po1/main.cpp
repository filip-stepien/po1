#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"
#include "vector2.h"
#include "ball.h"
#include "level.h"
#include <iostream>

int main()
{
    Game game;
    Error_handler error_handler(&game);

    game.init();

    bool err = error_handler.get_err_state();
    if (err) {
        std::cout << error_handler.get_err_msg();
        return -1;
    }
    
    Ball ball(200, 200, 8, 5);
    
    Level::pattern map = {
        { 1, 0, 1, 1, 0, 0 },
        { 0, 1, 0, 1, 0, 0 },
        { 1, 0, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1 }
    };

    Level level(50, 50, 700, 500, 200, map);

    ALLEGRO_EVENT event;
    bool running = true;
    while (running)
    {
        al_wait_for_event(game.queue, &event);
        switch (event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                level.render();
                al_flip_display();           
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                break;
        }
    }

    return 0;
}