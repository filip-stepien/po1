/**
 * @file powerup_manager.h
 * @brief Klasa menedżera modyfikatorów
 */

#pragma once

#include "powerup.h"
#include "player.h"
#include "shot.h"
#include "sounds.h"

#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <map>

/**
 * @brief Klasa menedżera modyfikatorów
 */
class Powerup_manager {
public:
	//! wektor obecnie istniejących modyfikatorów
	std::vector<Powerup*> powerups;
	//! wektor obecnie istniejących strzałów działka (laserów)
	std::vector<Shot*> shots;

	//! ilość modyfikatorów
	int powerup_count;
	//! koordynata Y, od kótej będzie rysowana tarcza
	int shield_y;
	//! wysokość tarczy
	int shield_height;

	//! czas, w którym rozpoczął się efekt przenikania przez cegiełki
	std::time_t noclip_effect_start;
	//! czas, w którym rozpoczął się efekt tarczy
	std::time_t shield_effect_start;
	//! czas, w którym rozpoczął się efekt modyfikacji szybkości piłki
	std::time_t ball_speed_effect_start;
	//! czas, w którym rozpoczął się efekt modyfikacji szybkości gracza
	std::time_t player_speed_effect_start;
	//! czas, w którym rozpoczął się efekt odwrócenia sterowania
	std::time_t invert_controls_effect_start;
	//! czas, w którym rozpoczął się efekt włączenia działka
	std::time_t cannon_effect_start;
	//! czas, w którym ostatni raz wystrzeliło działko
	std::time_t last_shot;

	//! grafika tarczy
	ALLEGRO_BITMAP* shield_sprite;

	/**
	 * @brief Konstruktor klasy menedżera modyfikatorów
     */
	Powerup_manager();

	/**
	 * @brief Generowanie modfykatora
	 * @param x koordynata X, od której modyfikator zostanie wygenerowany
	 * @param y koordynata Y, od której modyfikator zostanie wygenerowany
	 */
	void spawn_powerup(int x, int y);

	/**
	 * @brief Aktualizacja stanu modyfikatorów
	 * @param ball piłka
	 * @param player gracz
	 * @param sounds dźwięki gry
	 */
	void update_powerups(Ball& ball, Player& player, Sounds& sounds);

	/**
	 * @brief Rysowanie modyfikatorów
	 */
	void render_powerups();

	/**
	 * @brief Rysowanie efektów modyfikatorów
	 */
	void render_powerup_effects();

	/**
	 * @brief Aktualizacja stanu efektów modyfikatorów
	 * @param ball piłka
	 * @param player gracz
	 * @param sounds dźwięki gry
	 */
	void update_powerup_effects(Ball& ball, Player& player, Sounds& sounds);

	/**
	 * @brief Wyczyszczenie efektu przenikania przez cegiełki
	 * @param ball piłka
	 */
	void clear_noclip_effect(Ball& ball);

	/**
	 * @brief Wyczyszczenie efektu tarczy
	 * @param ball piłka
	 */
	void clear_shield_effect(Ball& ball);

	/**
	 * @brief Wyczyszczenie efektu modyfikacji szybkości piłki
	 * @param ball piłka
	 */
	void clear_ball_speed_effect(Ball& ball);

	/**
	 * @brief Wyczyszczenie efektu modyfikacji szybkości gracza
	 * @param player gracz
	 */
	void clear_player_speed_effect(Player& player);

	/**
	 * @brief Wyczyszczenie efektu odwrócenia sterowania
	 * @param player gracz
	 */
	void clear_invert_controls_effect(Player& player);

	/**
	 * @brief Wyczyszczenie efektu włączenia działka
	 * @param player gracz
	 */
	void clear_cannon_effect(Player& player);

	/**
	 * @brief Wyczyszczenie wszystkich efektów
	 * @param ball piłka
	 * @param player gracz
	 */
	void clear_all_effects(Ball& ball, Player& player);
};