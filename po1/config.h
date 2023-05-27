#pragma once
#include "allegro_includes.h"

struct Config {
    int window_width;
    int window_height;
    float volume;
    int player_gap;
    int font_size;
    int title_font_size;
    int button_font_size;
    int hovered_button_font_size;
    int fps;
    int ball_radius;
    int ball_speed;
    int player_x;
    int player_y;
    int player_width;
    int player_height;
    int player_speed;
    int text_y;
    int text_leading;
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
    int max_sway;
    double sway_frequency;
    int click_cooldown;
    ALLEGRO_COLOR powerup_color;
    ALLEGRO_COLOR solid_brick_color;
    ALLEGRO_COLOR double_brick_color;
    ALLEGRO_COLOR soft_brick_color;
    ALLEGRO_COLOR player_color;
    ALLEGRO_COLOR ball_color;
};

extern struct Config config;