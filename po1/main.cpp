#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"
#include "vector2.h"
#include "ball.h"
#include "level.h"
#include "player.h"
#include <iostream>
#include <cmath>
#include <numbers>

int main() {
    Game game;
    Error_handler error_handler(&game);

    game.init();

    bool err = error_handler.get_err_state();
    if (err) {
        std::cout << error_handler.get_err_msg();
        return -1;
    }
    
    Ball ball(500, 500, 8, 10);
    Player player(100, 20, 300, 550, 20);
    
    Level::pattern map = {
        { 1, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 1, 0 },
        { 1, 0, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 3, 0, 1, 0, 1, 0 },
        { 1, 2, 1, 3, 1, 3, 1, 2 },
    };

    Level level(0, 0, 800, 500, 200, map);
    level.init();

    ALLEGRO_EVENT event;
    bool running = true;
    while (running)
    {
        al_wait_for_event(game.queue, &event);
        switch (event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                if (player.moving_left) player.move_left();
                if (player.moving_right) player.move_right();

                al_draw_filled_rectangle(0, 0, config.window_width, config.window_height, al_map_rgb(0, 0, 0));

                for (int i = 0; i < level.bricks.size(); i++) {
                    Brick *brick = level.bricks[i];

                    if (ball.check_collision(brick)) {
                        ball.collide(brick);
                        brick->update();

                        if (brick->should_break) {
                            level.bricks.erase(level.bricks.begin() + i);
                            delete brick;
                        }
                    }
                }

                if (ball.check_collision(player))
                    ball.collide(player);

                ball.update();
                ball.render();

                player.render();
                level.render();

                al_flip_display();           
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_LEFT:
                        player.moving_left = true;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        player.moving_right = true;
                        break;
                }
                break;

            case ALLEGRO_EVENT_KEY_UP:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_LEFT:
                        player.moving_left = false;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        player.moving_right = false;
                        break;
                }
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                break;
        }
    }

    return 0;
}