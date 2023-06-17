/**
 * @file ball.h
 * @brief Klasa piłki
 */

#pragma once
#include "allegro_includes.h"
#include "vector2.h"
#include "player.h"
#include "brick.h"
#include "config.h"
#include "sounds.h"

#include <vector>
#include <cmath>

/**
 * @brief Klasa piłki
 */
class Ball {
public:
	//! promień piłki
	double radius;
	//! szybkość piłki
	double speed;
	//! maksymalna szybkość piłki
	double speed_cap;
	//! pozycja X w oknie
	int x; 
	//! pozycja Y w oknie
	int y;
	//! ostatnia uderzona cegiełka
	Brick* last_hit;
	//! prędkość piłki
	Vector2 velocity;
	//! czy piłka ma przenikać przez cegiełki
	bool noclip;
	//! czy aktywna jest tarcza
	bool shield_active;
	//! grafika piłki
	ALLEGRO_BITMAP* sprite;
	
	/**
	 * @brief Konstruktor klasy piłki
	 */
	Ball();

	/**
	 * @brief Ruch piłki
	 */
	void move();

	/**
	 * @brief Rysowanie piłki
	 */
	void render();

	/**
	 * @brief Sprawdzanie kolizji piłki z cegiełką
	 * @param brick cegiełka
	 * @return czy nastąpiła kolizja
	 */
	bool check_collision(const Brick* brick);

	/**
	 * @brief Sprawdzanie kolizji piłki z graczem
	 * @param player gracz
	 * @return czy nastąpiła kolizja
	 */
	bool check_collision(const Player& player);

	/**
	 * @brief Sprawdzanie czy piłka wypadła z planszy
	 * @return czy piłka wypadła z planszy
	 */
	bool did_fall_down();

	/**
	 * @brief Odbicie od ściany
	 * @param sounds dźwięki gry
	 */
	void handle_wall_collision(Sounds& sounds);

	/**
	 * @brief Odbicie od cegiełki
	 * @param brick cegiełka
	 */
	void collide(const Brick *brick);

	/**
	 * @brief Odbicie od gracza
	 * @param player gracz
	 */
	void collide(const Player& player);

	/**
	 * @brief Przyczepienie piłki do paletki gracza
	 * @param player gracz
	 */
	void stick(const Player& player);
};

