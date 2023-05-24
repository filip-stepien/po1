#include "allegro_includes.h"
#include "game.h"
#include "points.h"
#include "player.h"
#include "level.h"
#include "error_handler.h"
#include "ball.h"
#include "powerup_manager.h"
#include "shot.h"
#include "level_manager.h"
#include "title.h"

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
    
    Powerup_manager powerup_manager;
    Level_manager level_manager(game.font);

    level_manager.load_next_level();
    level_manager.current_level->reset();

    Title title(0, 0, "Arkanoid", game.font);

    unsigned int frame = 0;
    std::srand(std::time(nullptr));
    while (game.running) {
        game.get_event();
        switch (game.event.type) {
            case ALLEGRO_EVENT_TIMER:
                game.clear();

                if (player.moving_left) {
                    player.controls_inverted ? player.move_right() : player.move_left();
                }

                if (player.moving_right) {
                    player.controls_inverted ? player.move_left() : player.move_right();
                }

                if (level_manager.current_level->did_game_end() && !game.beginning) {
                    powerup_manager.shots.clear();
                    powerup_manager.powerups.clear();
                    powerup_manager.clear_all_effects(ball, player);

                    level_manager.load_next_level();
                    level_manager.current_level->reset();
                    game.beginning = true;
                    ball.last_hit = nullptr;
                }

                if (ball.did_fall_down()) {
                    powerup_manager.shots.clear();
                    powerup_manager.powerups.clear();
                    powerup_manager.clear_all_effects(ball, player);

                    level_manager.current_level_number = -1;
                    level_manager.current_stage_number = 1;
                    level_manager.load_next_level();
                    level_manager.current_level->reset();

                    game.beginning = true;
                    ball.last_hit = nullptr;
                    points.counter = 0;
                }

                if (game.beginning) {
                    ball.stick(player);
                } else {
                    for (int i = 0; i < level_manager.current_level->bricks.size(); i++) {
                        Brick* brick = level_manager.current_level->bricks[i];

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
                            level_manager.current_level->bricks.erase(level_manager.current_level->bricks.begin() + i);
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

                level_manager.current_level->render();
                player.render();
                points.render();
                ball.render();

                powerup_manager.update_powerups(ball, player);
                powerup_manager.update_powerup_effects(ball, player);
                powerup_manager.render_powerups();
                powerup_manager.render_powerup_effects();

                level_manager.render_level_and_stage_number();

                title.update(frame);
                title.render();
                game.render_frame();     
                frame++;
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