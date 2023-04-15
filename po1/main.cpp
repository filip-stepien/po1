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
    Ball ball;
    Player player;
    Level::pattern map = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    Level level(map);

    level.reset();

    while (game.running) {
        window::get_event(game.queue, &game.event);
        switch (game.event.type) {
            case ALLEGRO_EVENT_TIMER:
                window::clear();

                if (player.moving_left) {
                    player.move_left();
                }

                if (player.moving_right) {
                    player.move_right();
                }

                if (level.did_game_end()) {
                    level.reset();
                    game.beginning = true;
                }

                if (ball.did_fall_down()) {
                    game.beginning = true;
                    ball.last_hit = nullptr;
                }

                if (game.beginning) {
                    ball.stick(player);
                } else {
                    for (int i = 0; i < level.bricks.size(); i++) {
                        Brick* brick = level.bricks[i];

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

                    if (ball.check_collision(player)) {
                        ball.collide(player);
                    }
                    ball.handle_wall_collision();
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