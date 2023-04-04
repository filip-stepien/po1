#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"

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

    ALLEGRO_EVENT event;
    bool running = true;
    while (running)
    {
        al_wait_for_event(game.queue, &event);
        switch (event.type)
        {
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