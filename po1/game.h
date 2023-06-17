/**
 * @file game.h
 * @brief Klasa gry
 */

#pragma once
#include "allegro_includes.h"
#include "config.h"

/**
 * @brief Klasa gry
 */
class Game {
public:
    //! szerokość okna
    int width;
    //! wysokość okna
    int height;
    //! czy gra została zainicjalizowana
    bool game_initialized;
    //! czy klawiatura została zainicjalizowana
    bool keyboard_initialized;
    //! czy dodatek z kształtami został zainicjalizowany
    bool primitive_shapes_addon_initialized;
    //! czy dodatek z czcionką został zainicjalizowany
    bool font_addon_initialized;
    //! czy dodatek z czcionką został zainicjalizowany
    bool ttf_addon_initialized;
    //! czy dodatek z grafiką został zainicjalizowany
    bool image_addon_initialized;
    //! czy dodatek z dźwiękami został zainicjalizowany
    bool audio_addon_initialized;
    //! czy dodatek z kodekiem dźwięku został zainicjalizowany
    bool acodec_addon_initialized;
    //! czy myszka została zainicjalizowany
    bool mouse_initialized;
    //! okno gry
    ALLEGRO_DISPLAY* display;
    //! kolejka zdarzeń
    ALLEGRO_EVENT_QUEUE* queue;
    //! czcionka gry
    ALLEGRO_FONT* font;
    //! czcionka przycisku
    ALLEGRO_FONT* button_font;
    //! czcionka najechanego przycisku
    ALLEGRO_FONT* button_font_hovered;
    //! czcionka tytułu
    ALLEGRO_FONT* title_font;
    //! licznik gry
    ALLEGRO_TIMER* timer;
    //! zdarzenie gry
    ALLEGRO_EVENT event;
    //! czy trwa gra
    bool running;
    //! czy jest początek gry
    bool beginning;
    //! czy gra się rozpoczęła
    bool started;
    //! czy gra jest zapauzowana 
    bool paused;
    //! tło gry
    ALLEGRO_BITMAP* background;

    /**
     * @brief Konstruktor klasy gry
     */
    Game();

    /**
     * @brief Destruktor klasy gry
     */
    ~Game();

    /**
     * @brief Inicjalizacja gry
     */
    void init();

    /**
     * @brief Sprzątanie po grze
     */
    void destroy();

    /**
     * @brief Rysowanie klatki
     */
    void render_frame();

    /**
     * @brief Czyszczenie okna gry
     */
    void clear();

    /**
     * @brief Pobranie zdarzenia
     */
    void get_event();
};