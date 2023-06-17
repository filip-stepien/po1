/**
 * @file points.h
 * @brief Klasa licznika wyniku
 */

#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <fstream>
#include <string>
#include <iostream>

/**
 * @brief Klasa licznika wyniku
 */
class Points {
public:
	//! wynik
	int counter;
	//! najlepszy wynik
	int best_score;
	//! najlepszy wynik bieżącej sesji
	int local_best;
	//! najlepszy wynik przy załadowaniu gry
	int initial_best;
	//! koordynata X, od której będzie rysowany wynik
	int x;
	//! koordynata Y, od której będzie rysowany wynik
	int y;
	//! czcionka
	ALLEGRO_FONT* font;

	/**
	 * @brief Konstruktor klasy licznika wyniku
	 * @param font czcionka
	 */
	Points(ALLEGRO_FONT* font);

	/**
	 * @brief Destruktor klasy licznika wyniku
	 */
	~Points();

	/**
	 * @brief Rysowanie licznika wyniku
	 */
	void render();

	/**
	 * @brief Aktualizacja stanu licznika wyniku
	 */
	void update();

	/**
	 * @brief Zapisanie wyniku do pliku
	 */
	void save();
};