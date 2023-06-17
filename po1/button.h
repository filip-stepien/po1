/**
 * @file button.h
 * @brief Klasa przycisku
 */

#pragma once

#include "allegro_includes.h"
#include "config.h"
#include "sounds.h"

#include <iostream>

/**
 * @brief Klasa przycisku
 */
class Button {
public:
	//! koordynata X przycisku na planszy
	int x;
	//! koordynata Y przycisku na planszy
	int y;
	//! rzeczywista koordynata X; przechowuje koordynatę X, np. po powiększeniu przycisku przez najechanie
	int render_x;
	//! rzeczywista koordynata Y; przechowuje koordynatę Y, np. po powiększeniu przycisku przez najechanie
	int render_y;
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! odstęp czasowy, między którym przycisk może być kliknięty
	int click_cooldown;
	//! ostatnia klatka, w której wykonano kliknięcie
	unsigned int last_click_frame;
	//! tekst na przycisku
	const char* text;
	//! czy przycisk jest widoczny
	bool visible;
	//! czcionka
	ALLEGRO_FONT* font;
	//! czcionka po najechaniu
	ALLEGRO_FONT* font_hovered;
	//! obecnie używana czcionka
	ALLEGRO_FONT* current_font;

	/**
	 * @brief Konstruktor klasy przycisku
	 * @param x koordynata X na planszy
	 * @param y koordynata Y na planszy
	 * @param font czcionka
	 * @param font_hovered czcionka, która będzie używana po najechaniu na przycisk
	 */
	Button(int x, int y, const char* text, ALLEGRO_FONT* font, ALLEGRO_FONT* font_hovered);

	/**
	 * @brief Sprawdzenie czy najechano na przycisk
	 * @return czy najechano na przycisk
	 */
	bool is_hovered();

	/**
	 * @brief Sprawdzenie czy przycisk został kliknięty
	 * @return czy przycisk został kliknięty
	 */
	bool is_clicked();

	/**
	 * @brief Sprawdzenie czy przycisk może zostać kliknięty
	 * @return czy przycisk może zostać kliknięty
	 */
	bool is_on_cooldown();

	/**
	 * @brief Aktualizacja stanu przycisku
	 * @param frame obecna klatka gry
	 */
	void update(unsigned int frame);

	/**
	 * @brief Rysowanie przycisku
	 */
	void render();
};


/**
 * @brief Klasa przycisku z grafiką
 */
class Image_button : public Button {
public:
	//! grafika aktywnego przycisku
	ALLEGRO_BITMAP* background_on;
	//! grafika niekatywnego przycisku
	ALLEGRO_BITMAP* background_off;
	//! czy przycisk jest aktywny
	bool on;

	/**
	 * @brief Konstruktor klasy przycisku z grafiką
	 * @param x koordynata X na planszy
	 * @param y koordynata Y na planszy
	 * @param background_down grafika aktywnego przycisku
	 * @param background_up grafika nieaktywnego przycisku
	 */
	Image_button(int x, int y, const char* background_down, const char* background_up);

	/**
	 * @brief Aktualizacja stanu przycisku
	 * @param frame obecna klatka gry
	 * @param sounds dźwięki gry
	 */
	void update(unsigned int frame, Sounds& sounds);

	/**
	 * @brief Rysowanie przycisku
	 */
	void render();
};