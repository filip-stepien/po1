#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"
#include "ball.h"
#include "level.h"
#include "player.h"
#include "points.h"
#include "window.h"

#include <iostream>

int main() {
    Game game;
    Error_handler error_handler(&game);

    game.init();
    bool err = error_handler.get_err_state();
    if (err) {
        std::cout << error_handler.get_err_msg();
        return -1;
    }

    Points points(game.font);
    Ball ball(&game, &points);
    Player player;
    Level::pattern map = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 3, 0, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 3, 1, 0, 3, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    Level level(map, &game, &points);

    level.init();

    while (game.running) {
        window::get_event(game.queue, &game.event);
        switch (game.event.type) {
            case ALLEGRO_EVENT_TIMER:
                window::clear();

                level.handle_game_end();

                if (player.moving_left) player.move_left();
                if (player.moving_right) player.move_right();

                if (game.beginning) {
                    ball.stick(player);
                }
                else {
                    ball.handle_collision();
                    ball.handle_collision(level.bricks);
                    ball.handle_collision(player);
                    ball.move();
                }

                level.render();
                player.render();
                points.render();
                ball.render();

                window::render_frame();           
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                switch (game.event.keyboard.keycode) {
                    case ALLEGRO_KEY_LEFT:
                        player.moving_left = true;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        player.moving_right = true;
                        break;
                    case ALLEGRO_KEY_SPACE: 
                        game.beginning = false;
                        break;
                }
                break;

            case ALLEGRO_EVENT_KEY_UP:
                switch (game.event.keyboard.keycode) {
                    case ALLEGRO_KEY_LEFT:
                        player.moving_left = false;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        player.moving_right = false;
                        break;
                }
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                game.running = false;
                break;
        }
    }

    return 0;
}