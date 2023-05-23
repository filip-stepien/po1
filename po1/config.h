#pragma once
#include "allegro_includes.h"

struct Config {
    int window_width;
    int window_height;
    int player_gap;
    int font_size;
    int fps;
    int ball_radius;
    int ball_speed;
    int player_x;
    int player_y;
    int player_width;
    int player_height;
    int player_speed;
    int points_width;
    int points_height;
    int points_x;
    int points_y;
    int powerup_radius;
    int powerup_speed;
    int shield_y;
    int shield_height;
    int powerup_duration;
    int powerup_chance;
    double ball_speed_effect_multiplier;
    double player_speed_effect_multiplier;
    int shot_width;
    int shot_height;
    int shot_speed;
    int cannon_width;
    int cannon_height;
    ALLEGRO_COLOR powerup_color;
    ALLEGRO_COLOR solid_brick_color;
    ALLEGRO_COLOR double_brick_color;
    ALLEGRO_COLOR soft_brick_color;
    ALLEGRO_COLOR player_color;
    ALLEGRO_COLOR ball_color;
};

extern struct Config config;