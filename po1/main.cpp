#include "allegro_includes.h"
#include "config.h"
#include "game.h"
#include "error_handler.h"
#include "vector2.h"
#include "ball.h"
#include "level.h"
#include "player.h"
#include "points.h"

#include <iostream>
#include <cmath>
#include <numbers>

namespace window {
    void render_frame() {
        al_flip_display();
    }

    void clear() {
        al_draw_filled_rectangle(0, 0, config.window_width, config.window_height, al_map_rgb(0, 0, 0));
    }
}

int main() {
    Game game;
    Error_handler error_handler(&game);

    game.init();

    bool err = error_handler.get_err_state();
    if (err) {
        std::cout << error_handler.get_err_msg();
        return -1;
    }
    
    Ball ball(500, 500, 8, 6);
    Player player(200, 20, 300, 550, 10);
    
    Level::pattern map = {
        { 1, 2, 1, 2, 1, 2, 1, 2 },
        { 2, 1, 2, 1, 2, 1, 2, 1 },
        { 1, 2, 1, 2, 1, 2, 1, 2 },
        { 2, 1, 2, 1, 2, 1, 2, 1 },
        { 1, 2, 1, 2, 1, 2, 1, 2 },
    };

    Level level(0, 0, 800, 500, 200, map);
    level.init();

    Points points(300, 375, 200, 100, game.font);

    while (game.running)
    {
        al_wait_for_event(game.queue, &game.event);
        switch (game.event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                window::clear();

                if (player.moving_left) player.move_left();
                if (player.moving_right) player.move_right();

                for (int i = 0; i < level.bricks.size(); i++) {
                    Brick *brick = level.bricks[i];

                    if (ball.check_collision(brick) && ball.last_hit != brick) {
                        ball.last_hit = brick;
                        ball.collide(brick);
                        brick->update();

                        if (brick->should_break) {
                            level.bricks.erase(level.bricks.begin() + i);
                            delete brick;
                            points.counter++;
                        }
                    }
                }

                if (ball.check_collision(player))
                    ball.collide(player);

                player.render();
                level.render();

                ball.update();
                ball.render();

                points.render();

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