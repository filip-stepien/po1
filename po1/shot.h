/**
 * @file shot.h
 * @brief Klasa lasera
 */

#pragma once

#include "vector2.h"
#include "brick.h"
#include "config.h"

/**
 * @brief Klasa lasera
 */
class Shot {
public:
	//! koordynata X, od której będzie rysowany laser
	int x;
	//! koordynata Y, od której będzie rysowany laser
	int y;
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! prędkość
	Vector2 velocity;
	//! szybkość
	int speed;
	//! grafika
	ALLEGRO_BITMAP* sprite;

	/**
	 * @brief Konstruktor klasy lasera
	 * @param x koordynata X, od której będzie rysowany lase
	 * @param y koordynata Y, od której będzie rysowany laser
	 */
	Shot(int x, int y);

	/**
	 * @brief Ruch lasera
	 */
	void move();

	/**
	 * @brief Rysowanie lasera
	 */
	void render();

	/**
	 * @brief Sprawdzenie kolizji lasera z cegiełką
	 * @param brick cegiełka
	 * @return czy nastąpiła kolizja
	 */
	bool check_collision(Brick* brick);
};