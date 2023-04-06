#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"
#include "vector2.h"
#include "ball.h"
#include <iostream>

int main()
{
    struct Config config = { 800, 600, 16, 30 };
    Game game(config);
    Error_handler error_handler(&game);

    game.init();

    bool err = error_handler.get_err_state();
    if (err) {
        std::cout << error_handler.get_err_msg();
        return -1;
    }
    
    Ball ball(200, 200, 8, 5);
    

    ALLEGRO_EVENT event;
    bool running = true;
    while (running)
    {
        al_wait_for_event(game.queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            al_draw_filled_rectangle(0, 0, 800, 600, al_map_rgb(0, 0, 0));
            ball.update();
            ball.render();
            al_flip_display();           
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
                running = false;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                running = false;
            break;
        }
    }

    return 0;
}