#pragma once
#include "allegro_includes.h"
#include "config.h"

class Game {
public:
    int width;
    int height;
    bool game_initialized;
    bool keyboard_initialized;
    bool primitive_shapes_addon_initialized;
    bool font_addon_initialized;
    bool ttf_addon_initialized;
    bool image_addon_initialized;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* font;
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT event;
    bool running;
    bool beginning;
    ALLEGRO_BITMAP* background;

    Game();
    ~Game();

    void init();
    void destroy();
    void render_frame();
    void clear();
    void get_event();
};