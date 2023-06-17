/**
 * @file sounds.h
 * @brief Klasa dźwięków gry
 */

#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <vector>

/**
 * @brief Klasa dźwięków gry
 */
class Sounds {
public:
	//! muzyka
	ALLEGRO_SAMPLE_INSTANCE* music;
	//! dźwięk wybrania opcji
	ALLEGRO_SAMPLE_INSTANCE* option;

	//! dźwięki odbić piłki
	std::vector<ALLEGRO_SAMPLE_INSTANCE*> bounces;
	//! dźwięki zebrania modyfikatorów
	std::vector<ALLEGRO_SAMPLE_INSTANCE*> powerups;
	//! dźwięki strzałów działka (laserów)
	std::vector<ALLEGRO_SAMPLE_INSTANCE*> shots;

	//! ostatni dodany element do wektora dźwięków odbić piłki
	int bounce_idx;
	//! ostatni dodany element do wektora dźwięków zebrania modyfikatorów
	int powerup_idx;
	//! ostatni dodany element do wektora dźwięków strzałów działka (laserów)
	int shot_idx;

	/**
	 * @brief Konstruktor klasy dźwięków gry
	 */
	Sounds();

	/**
	 * @brief Odtworzenie muzyki gry
	 */
	void play_music();

	/**
	 * @brief Odtworzenie dźwięku odbicia piłki
	 */
	void play_bounce();

	/**
	 * @brief Odtworzenie dźwięku strzału działka (lasera)
	 */
	void play_shot();

	/**
	 * @brief Odtworzenie dźwięku zebrania modyfikatora
	 */
	void play_powerup();

	/**
	 * @brief Odtworzenie dźwięku wybrania opcji
	 */
	void play_option();

	/**
	 * @brief Wyciszenie dźwięków
	 */
	void mute();

	/**
	 * @brief Wyłączenie wyciszenia dźwięków
	 */
	void unmute();
};