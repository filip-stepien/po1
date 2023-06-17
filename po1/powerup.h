/**
 * @file powerup.h
 * @brief Klasa modyfikatora
 */

#pragma once

#include "allegro_includes.h"
#include "vector2.h"
#include "ball.h"
#include "player.h"
#include "config.h"

#include <vector>
#include <iostream>

/**
 * @brief Klasa modyfikatora
 */
class Powerup {
public:
	//! prefix typu modyfikatora
	using effects = enum effects { EFFECT_NOCLIP, EFFECT_SHIELD, EFFECT_BALL_SPEED, EFFECT_PLAYER_SPEED, EFFECT_INVERT_CONTROLS, EFFECT_CANNON };

	//! typ modyfikatora
	effects effect;
	//! promień
	double radius;
	//! szybkość
	double speed;
	//! koordynata X, od której będzie rysowany modyfikator
	int x;
	//! koordynata Y, od której będzie rysowany modyfikator
	int y;
	//! prędkość
	Vector2 velocity;
	//! grafika
	ALLEGRO_BITMAP* sprite;

	/**
	 * @brief Konstruktor klasy modyfikatora
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Ruch modyfikatora
	 */
	void move();

	/**
	 * @brief Rysowanie modyfikatora
	 */
	void render();

	/**
	 * @brief Sprawdzenie kolizji modyfikatora z graczem
	 * @param player gracz
	 * @return czy nastąpiła kolizja
	 */
	bool check_collision(const Player& player);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	virtual void collide(Ball& ball, Player& player);

	/**
	 * @brief Sprawdzenie czy modyfikator wypadł z planszy
	 * @return czy modyfikator wypadł z planszy
	 */
	bool did_fall_down();
};

/**
 * @brief Klasa modyfikatora przenikającego przez cegiełki
 */
class Powerup_noclip : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora przenikającego przez cegiełki
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_noclip(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};

/**
 * @brief Klasa modyfikatora tworzącego tarczę
 */
class Powerup_shield : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora tworzącego tarczę
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_shield(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};

/**
 * @brief Klasa modyfikatora modyfikującego szybkość piłki
 */
class Powerup_ball_speed : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora modyfikującego szybkość piłki
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_ball_speed(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};

/**
 * @brief Klasa modyfikatora modyfikującego szybkość gracza
 */
class Powerup_player_speed : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora modyfikującego szybkość gracza
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_player_speed(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};

/**
 * @brief Klasa modyfikatora odwracającego sterowanie
 */
class Powerup_invert_controls : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora odwracającego sterowanie
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_invert_controls(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};

/**
 * @brief Klasa modyfikatora włączającego działko
 */
class Powerup_cannon : public Powerup {
public:
	/**
	 * @brief Konstruktor klasy modyfikatora włączającego działko
	 * @param x koordynata X, od której będzie rysowany modyfikator
	 * @param y koordynata Y, od której będzie rysowany modyfikator
	 * @param sprite grafika
	 * @param effect typ modyfikatora
	 */
	Powerup_cannon(int x, int y, const char* sprite, effects effect);

	/**
	 * @brief Efekt modyfikatora po kolizji z graczem
	 * @param ball piłka
	 * @param player gracz
	 */
	void collide(Ball& ball, Player& player);
};