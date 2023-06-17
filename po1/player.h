/**
 * @file player.h
 * @brief Klasa gracza
 */

#pragma once
#include "allegro_includes.h"
#include "config.h"

/**
 * @brief Klasa gracza
 */
class Player {
public:
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! szerokość działka
	int cannon_width;
	//! wysokość działka
	int cannon_height;
	//! koordynata X, od której będzie rysowany gracz
	int x;
	//! koordynata Y, od której będzie rysowany gracz
	int y;
	//! szybkość gracza
	double speed;
	//! maksymalna szybkość gracza
	double speed_cap;
	//! grafika gracza
	ALLEGRO_BITMAP* sprite;
	//! grafika działka
	ALLEGRO_BITMAP* cannon_sprite;
	//! czy gracz porusza się w prawo
	bool moving_right;
	//! czy gracz porusza się w lewo
	bool moving_left;
	//! czy sterowanie jest odwrócone
	bool controls_inverted;
	//! czy działko jest aktywne
	bool cannon_active;

	/**
	* @brief Konstruktor klasy gracza
	*/
	Player();

	/**
	 * @brief Rysowanie gracza
	 */
	void render();

	/**
	 * @brief Ruch gracza w prawo
	 */
	void move_right();

	/**
	 * @brief Ruch gracza w lewo
	 */
	void move_left();

	/**
	 * @brief Zresetowanie stanu gracza
	 */
	void reset();
};