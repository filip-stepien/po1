#include "allegro_includes.h"
#include "game.h"
#include "config.h"

Game::Game(struct Config config) {
    this->config = config;
    game_initialized = false;
    keyboard_initialized = false;
    primitive_shapes_addon_initialized = false;
    font_addon_initialized = false;
    ttf_addon_initialized = false;
    display = NULL;
    queue = NULL;
    font = NULL;
    timer = NULL;
}

Game::~Game() {
    destroy();
}

void Game::init() {
    game_initialized = al_init();
    keyboard_initialized = al_install_keyboard();
    primitive_shapes_addon_initialized = al_init_primitives_addon();
    font_addon_initialized = al_init_font_addon();
    ttf_addon_initialized = al_init_ttf_addon();
    display = al_create_display(config.window_width, config.window_height);
    queue = al_create_event_queue();
    font = al_load_font("Arial.ttf", config.font_size, NULL);
    timer = al_create_timer(1.0 / (double)config.fps);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
}

void Game::destroy() {
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
