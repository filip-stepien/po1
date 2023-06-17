/**
 * @file brick.h
 * @brief Klasa cegiełki
 */

#pragma once
#include "allegro_includes.h"
#include "config.h"

/**
 * @brief Klasa cegiełki
 */
class Brick {
	public:
	//! koordynata X na planszy
	int x;
	//! koordynata Y na planszy
	int y;
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! czy cegiełka powinna się zniszczyć
	bool should_break;
	//! grafika
	ALLEGRO_BITMAP* sprite;

	/**
	 * @brief Konstruktor klasy cegiełki
	 * @param x koordynata X na planszy
	 * @param y koordynata Y na planszy
	 * @param width szerokość
	 * @param height wysokość
	 * @param sprite grafika
	 */
	Brick(int x, int y, int width, int height, const char* sprite);

	/**
	 * @brief Rysowanie cegiełki
	 */
	virtual void render();

	/**
	 * @brief Aktualizacja stanu cegiełki
	 */
	virtual void update();
};

/**
 * @brief Klasa cegiełki niszczonej dwoma uderzeniami
 */
class Brick_double : public Brick {
public:
	//! ile razy cegiełka została uderzona
	int hit_count;
	//! grafika tarczy cegiełki
	ALLEGRO_BITMAP* shield_sprite;

	/**
	 * @brief Konstruktor klasy cegiełki niszczonej dwoma uderzeniami
	 * @param x koordynata X na planszy
	 * @param y koordynata Y na planszy
	 * @param width szerokość
	 * @param height wysokość
	 * @param sprite grafika
	 */
	Brick_double(int x, int y, int width, int height, const char* sprite);

	/**
	 * @brief Aktualizacja stanu cegiełki
	 */
	void update();

	/**
	 * @brief Rysowanie cegiełki
	 */
	void render();
};

/**
 * @brief Klasa niezniszczalnej cegiełki
 */
class Brick_solid : public Brick {
public:
	//! grafika tarczy cegiełki
	ALLEGRO_BITMAP* shield_sprite;

	/**
	 * @brief Konstruktor klasy niezniszczalnej cegiełki
	 * @param x koordynata X na planszy
	 * @param y koordynata Y na planszy
	 * @param width szerokość
	 * @param height wysokość
	 * @param sprite grafika
	 */
	Brick_solid(int x, int y, int width, int height, const char* sprite);

	/**
	 * @brief Aktualizacja stanu cegiełki
	 */
	void update();

	/**
	 * @brief Rysowanie cegiełki
	 */
	void render();
};