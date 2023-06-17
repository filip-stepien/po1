/**
 * @file title.h
 * @brief Klasa tytułu
 */

#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <iostream>
#include <cmath>

/**
 * @brief Klasa tytułu
 */
class Title {
public:
	//! koordynata X, od ktorej będzie rysowany tytuł
	int x;
	//! koordynata Y, od ktorej będzie rysowany tytuł
	int y;
	//! rzeczywista koordynata Y lewitującego tytułu
	int render_y;
	//! maksymalne odchylenie
	int max_sway;
	//! częstotliwość lewitacji tytułu
	double sway_frequency;
	//! tekst tytułu
	const char* text;
	//! czcionka
	ALLEGRO_FONT* font;
	//! czy tytuł ma być widoczny
	bool visible;

	/**
	 * @brief Konstruktor klasy tytułu
	 * @param x koordynata X, od ktorej będzie rysowany tytuł
	 * @param y koordynata Y, od ktorej będzie rysowany tytuł
	 * @param text tekst tytułu
	 * @param font czcionka
	 */
	Title(int x, int y, const char* text, ALLEGRO_FONT* font);

	/**
	 * @brief Aktualizacja stanu tytułu
	 * @param frame obecna klatka gry
	 */
	void update(unsigned int frame);

	/**
	 * @brief Rysowanie tytułu
	 */
	void render();
};