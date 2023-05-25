#pragma once

#include "powerup.h"
#include "player.h"
#include "shot.h"

#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <map>

class Powerup_manager {
public:
	std::vector<Powerup*> powerups;
	std::vector<Shot*> shots;

	int powerup_count;
	int shield_y;
	int shield_height;

	std::time_t noclip_effect_start;
	std::time_t shield_effect_start;
	std::time_t ball_speed_effect_start;
	std::time_t player_speed_effect_start;
	std::time_t invert_controls_effect_start;
	std::time_t cannon_effect_start;
	std::time_t last_shot;

	Powerup_manager();
	void spawn_powerup(int x, int y);
	void update_powerups(Ball& ball, Player& player);
	void render_powerups();
	void render_powerup_effects();
	void update_powerup_effects(Ball& ball, Player& player);
	void clear_noclip_effect(Ball& ball);
	void clear_shield_effect(Ball& ball);
	void clear_ball_speed_effect(Ball& ball);
	void clear_player_speed_effect(Player& player);
	void clear_invert_controls_effect(Player& player);
	void clear_cannon_effect(Player& player);
	void clear_all_effects(Ball& ball, Player& player);
};