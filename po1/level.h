/**
 * @file level.h
 * @brief Klasa poziomu
 */

#pragma once
#include "allegro_includes.h"
#include "brick.h"
#include "config.h"

#include <vector>

/**
 * @brief Klasa poziomu
 */
class Level {
public:
	//! prefix dla szablonu poziomu
	using pattern = std::vector<std::vector<int>>;

	//! koordynata X, od której będzie rysowany poziom
	int x;
	//! koordynata Y, od której będzie rysowany poziom
	int y;
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! odstęp między poziomem i graczem
	int player_gap;
	//! ilość niezniczalnych cegiełek występujących w poziomie
	int solid_brick_count;
	//! cegiełki poziomu
	std::vector<Brick*> bricks;
	//! szablon poziomu
	pattern map;
	
	/**
	 * @brief Konstruktor klasy poziomu
	 * @param map szablon poziomu
     */
	Level(pattern map);

	/**
	 * @brief Konstruktor klasy poziomu
	 * @param x koordynata X, od której będzie rysowany poziom
	 * @param y koordynata Y, od której będzie rysowany poziom
	 * @param width szerokość
	 * @param height wysokość
	 * @param player_gap odstęp między poziomem i graczem
	 * @param map szablon poziomu
	 */
	Level(int x, int y, int width, int height, int player_gap, pattern map);

	/**
	 * @brief Destruktor klasy poziomu
	 */
	~Level();

	/**
	 * @brief Restart poziomu
	 */
	void reset();

	/**
	 * @brief Rysowanie poziomu
	 */
	void render();

	/**
	 * @brief Sprawdzenie, czy gra się zakończyła
	 * @return czy gra się zakończyła
	 */
	bool did_game_end();
};