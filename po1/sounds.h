#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <vector>

class Sounds {
public:
	ALLEGRO_SAMPLE_INSTANCE* music;
	ALLEGRO_SAMPLE_INSTANCE* option;

	std::vector<ALLEGRO_SAMPLE_INSTANCE*> bounces;
	std::vector<ALLEGRO_SAMPLE_INSTANCE*> powerups;
	std::vector<ALLEGRO_SAMPLE_INSTANCE*> shots;
	int bounce_idx;
	int powerup_idx;
	int shot_idx;

	Sounds();
	void play_music();
	void play_bounce();
	void play_shot();
	void play_powerup();
	void play_option();
	void mute();
	void unmute();
};