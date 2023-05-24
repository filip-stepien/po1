#include "game.h"

Game::Game() {
    this->width = config.window_width;
    this->height = config.window_height;
    this->game_initialized = false;
    this->keyboard_initialized = false;
    this->primitive_shapes_addon_initialized = false;
    this->font_addon_initialized = false;
    this->ttf_addon_initialized = false;
    this->image_addon_initialized = false;
    this->mouse_initialized = false;
    this->display = nullptr;
    this->queue = nullptr;
    this->font = nullptr;
    this->button_font = nullptr;
    this->button_font_hovered = nullptr;
    this->event = {};
    this->timer = nullptr;
    this->running = true;
    this->beginning = true;
    this->background = nullptr;
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
    image_addon_initialized = al_init_image_addon();
    mouse_initialized = al_install_mouse();
    display = al_create_display(config.window_width, config.window_height);
    queue = al_create_event_queue();
    font = al_load_font("PixeloidSans.ttf", config.font_size, 0);
    title_font = al_load_font("PixeloidSans.ttf", config.title_font_size, 0);
    button_font = al_load_font("PixeloidSans.ttf", config.button_font_size, 0);
    button_font_hovered = al_load_font("PixeloidSans.ttf", config.hovered_button_font_size, 0);
    timer = al_create_timer(1.0l / static_cast<double>(config.fps));
    background = al_load_bitmap("background.png");

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

void Game::render_frame() {
    al_flip_display();
}

void Game::clear() {
    al_draw_bitmap(background, 0, 0, 0);
}

void Game::get_event() {
    al_wait_for_event(queue, &event);
}