/**
 * @file config.h
 * @brief Konfiguracja gry
 */

#pragma once
#include "allegro_includes.h"

//! struktura przechowująca zmienne gry
struct Config {
    //! szerokość okna
    int window_width;
    //! wysokość okna
    int window_height;
    //! głośność
    float volume;
    //! odstęp między graczem i cegiełkami
    int player_gap;
    //! wielkość czionki
    int font_size;
    //! wielkość czicionki tytułu
    int title_font_size;
    //! wielkośc czcionki na przycisku
    int button_font_size;
    //! wielkośc czcionki na najechanym przycisku
    int hovered_button_font_size;
    //! ilość klatek na sekundę
    int fps;
    //! promień piłki
    int ball_radius;
    //! szybkość piłki
    int ball_speed;
    //! początkowa koordynata X gracza
    int player_x;
    //! koordynata Y gracza
    int player_y;
    //! szerokość gracza
    int player_width;
    //! wysokość gracza
    int player_height;
    //! szybkość gracza
    int player_speed;
    //! koordynata Y od której będzie rysowany tekst
    int text_y;
    //! interlinia tekstu
    int text_leading;
    //! promień modyfikatora
    int powerup_radius;
    //! szybkość modyfikatora
    int powerup_speed;
    //! skoordynata Y od której będzie rysowana tarcza
    int shield_y;
    //! wysokość tarczy
    int shield_height;
    //! czas trwania modyfikatora
    int powerup_duration;
    //! szansa na wygenerowanie modyfikatora
    int powerup_chance;
    //! mnożnik szybkości piłki
    double ball_speed_effect_multiplier;
    //! mnożnik szybkości gracza
    double player_speed_effect_multiplier;
    //! szerokość lasera
    int shot_width;
    //! wysokość lasera
    int shot_height;
    //! szybkość lasera
    int shot_speed;
    //! szerokość działka
    int cannon_width;
    //! wysokość działka
    int cannon_height;
    //! maksymalne wychylenie lewitującego tekstu
    int max_sway;
    //! częstotliwość lewitującego tekstu
    double sway_frequency;
    //! odstęp czasowy, między którym przycisk może być kliknięty
    int click_cooldown;
};

//! struktura przechowująca zmienne gry
extern struct Config config;