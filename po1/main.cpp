#include "allegro_includes.h"
#include "game.h"
#include "points.h"
#include "player.h"
#include "level.h"
#include "error_handler.h"
#include "ball.h"
#include "window.h"
#include "powerup_manager.h"
#include "shot.h"

#include <iostream>
#include <vector>

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
        { 0, 0, 1, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 2, 2, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    Level level(map);

    Powerup_manager powerup_manager;

    level.reset();

    std::srand(std::time(nullptr));
    while (game.running) {
        window::get_event(game.queue, &game.event);
        switch (game.event.type) {
            case ALLEGRO_EVENT_TIMER:
                window::clear();

                if (player.moving_left) {
                    player.controls_inverted ? player.move_right() : player.move_left();
                }

                if (player.moving_right) {
                    player.controls_inverted ? player.move_left() : player.move_right();
                }

                if (level.did_game_end()) {
                    level.reset();
                    game.beginning = true;
                    points.counter = 0;
                }

                if (ball.did_fall_down()) {
                    game.beginning = true;
                    ball.last_hit = nullptr;
                    points.counter = 0;
                }

                if (game.beginning) {
                    ball.stick(player);
                } else {
                    for (int i = 0; i < level.bricks.size(); i++) {
                        Brick* brick = level.bricks[i];

                        for (int j = 0; j < powerup_manager.shots.size(); j++) {
                            Shot* shot = powerup_manager.shots[j];

                            if (shot->check_collision(brick)) {
                                brick->update();
                                powerup_manager.shots.erase(powerup_manager.shots.begin() + j);
                                delete shot;
                            }
                        }

                        if (ball.check_collision(brick) && ball.last_hit != brick) {
                            ball.last_hit = brick;
                            ball.collide(brick);
                            brick->update();
                        }

                        if (brick->should_break) {
                            level.bricks.erase(level.bricks.begin() + i);
                            delete brick;
                            points.counter++;

                            powerup_manager.spawn_powerup(ball.x, ball.y);
                        }
                    }

                    if (ball.check_collision(player)) {
                        ball.collide(player);
                    }
                    ball.handle_wall_collision();
                    ball.move();
                }

                points.update();

                level.render();
                player.render();
                points.render();
                ball.render();

                powerup_manager.update_powerups(ball, player);
                powerup_manager.update_powerup_effects(ball, player);
                powerup_manager.render_powerups();
                powerup_manager.render_powerup_effects();

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