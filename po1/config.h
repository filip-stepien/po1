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
    ALLEGRO_COLOR solid_brick_color;
    ALLEGRO_COLOR double_brick_color;
    ALLEGRO_COLOR soft_brick_color;
    ALLEGRO_COLOR player_color;
    ALLEGRO_COLOR ball_color;
};

extern struct Config config;