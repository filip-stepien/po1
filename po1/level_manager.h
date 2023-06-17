/**
 * @file level_manager.h
 * @brief Klasa menedżera poziomów
 */

#pragma once

#include "level.h"
#include "level_patterns.h"

#include <vector>

/**
 * @brief Klasa menedżera poziomów
 */
class Level_manager {
public:
	//! koordynata X, od której będą rysowane poziomy
	int x;
	//! koordynata Y, od której będą rysowane poziomy
	int y;
	//! obecny numer etapu
	int current_stage_number;
	//! obecny numer poziomu
	int current_level_number;
	//! mnożnik etapu
	double stage_multiplier;
	//! wektor poziomów gry
	std::vector<Level::pattern> patterns;
	//! obecny poziom
	Level* current_level;
	//! czcionka
	ALLEGRO_FONT* font;
	
	/**
	 * @brief Konstruktor klasy menedżera poziomów
	 * @param font czcionka
	 */
	Level_manager(ALLEGRO_FONT* font);

	/**
	 * @brief Załadowanie następnego poziomu
	 */
	void load_next_level();

	/**
	 * @brief Rysowanie numeru etapu i poziomu
	 */
	void render_level_and_stage_number();
};