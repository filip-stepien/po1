#pragma once
#include "allegro_includes.h"
#include "config.h"

class Game {
public:
    bool game_initialized;
    bool keyboard_initialized;
    bool primitive_shapes_addon_initialized;
    bool font_addon_initialized;
    bool ttf_addon_initialized;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* font;
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT event;
    bool running;
    bool beginning;

    Game();
    ~Game();

    void init();
    void destroy();
};