#include "powerup_manager.h"

Powerup_manager::Powerup_manager() {
	this->shield_y = config.shield_y;
	this->shield_height = config.shield_height;
	this->noclip_effect_start = 0;
	this->shield_effect_start = 0;
	this->ball_speed_effect_start = 0;
	this->player_speed_effect_start = 0;
	this->invert_controls_effect_start = 0;
	this->cannon_effect_start = 0;
	this->powerup_count = 6;
	this->last_shot = 0;
}

void Powerup_manager::spawn_powerup(int x, int y) {
	int random_number = std::rand() % 100;
	if (random_number > config.powerup_chance) return;

	int random_powerup = rand() % powerup_count;
	switch (random_powerup) {
		case Powerup::EFFECT_NOCLIP: 
			powerups.push_back(new Powerup_noclip(x, y, Powerup::EFFECT_NOCLIP)); 
			break;
		case Powerup::EFFECT_SHIELD: 
			powerups.push_back(new Powerup_shield(x, y, Powerup::EFFECT_SHIELD)); 
			break;
		case Powerup::EFFECT_BALL_SPEED: 
			powerups.push_back(new Powerup_ball_speed(x, y, Powerup::EFFECT_BALL_SPEED)); 
			break;
		case Powerup::EFFECT_PLAYER_SPEED: 
			powerups.push_back(new Powerup_player_speed(x, y, Powerup::EFFECT_PLAYER_SPEED)); 
			break;
		case Powerup::EFFECT_INVERT_CONTROLS: 
			powerups.push_back(new Powerup_invert_controls(x, y, Powerup::EFFECT_INVERT_CONTROLS)); 
			break;
		case Powerup::EFFECT_CANNON: 
			powerups.push_back(new Powerup_cannon(x, y, Powerup::EFFECT_CANNON)); 
			break;
	}
}

void Powerup_manager::update_powerups(Ball& ball, Player& player) {
	for (int i = 0; i < powerups.size(); i++) {
		Powerup* powerup = powerups[i];

		powerup->move();

		if (powerup->check_collision(player)) {
			switch (powerup->effect) {
				case Powerup::EFFECT_NOCLIP: noclip_effect_start = std::time(nullptr); break;
				case Powerup::EFFECT_SHIELD: shield_effect_start = std::time(nullptr); break;
				case Powerup::EFFECT_BALL_SPEED: ball_speed_effect_start = std::time(nullptr); break;
				case Powerup::EFFECT_PLAYER_SPEED: player_speed_effect_start = std::time(nullptr); break;
				case Powerup::EFFECT_INVERT_CONTROLS: invert_controls_effect_start = std::time(nullptr); break;
				case Powerup::EFFECT_CANNON:
					cannon_effect_start = std::time(nullptr); 
					last_shot = std::time(nullptr);
					break;
			}

			powerup->collide(ball, player);
			powerups.erase(powerups.begin() + i);
			delete powerup;
		}
	}
}

void Powerup_manager::render_powerups() {
	for (int i = 0; i < powerups.size(); i++) {
		Powerup* powerup = powerups[i];
		powerup->render();
	}
}

void Powerup_manager::render_powerup_effects() {
	if (shield_effect_start > 0)
	al_draw_filled_rectangle(0, config.shield_y, config.window_width, config.shield_y + config.shield_height, al_map_rgb(255, 255, 255));

	for (int i = 0; i < shots.size(); i++)
	shots[i]->render();
}

void Powerup_manager::update_powerup_effects(Ball& ball, Player& player) {
	std::time_t current_time = std::time(nullptr);

	if (current_time - noclip_effect_start == config.powerup_duration) clear_noclip_effect(ball);
	if (current_time - shield_effect_start == config.powerup_duration) clear_shield_effect(ball);
	if (current_time - ball_speed_effect_start == config.powerup_duration) clear_ball_speed_effect(ball);
	if (current_time - player_speed_effect_start == config.powerup_duration) clear_player_speed_effect(player);
	if (current_time - invert_controls_effect_start == config.powerup_duration) clear_invert_controls_effect(player);
	if (current_time - cannon_effect_start == config.powerup_duration) clear_cannon_effect(player);

	if (current_time - last_shot == 1) {
		shots.push_back(new Shot(player.x + player.width / 2 - config.shot_width / 2, player.y - player.height - player.cannon_height - config.shot_height));
		last_shot = current_time;
	}

	for (int i = 0; i < shots.size(); i++) {
		Shot* shot = shots[i];
		shot->move();
		if (shot->y + shot->height < 0) {
			shots.erase(shots.begin() + i);
			delete shot;
		}
	}
}

void Powerup_manager::clear_noclip_effect(Ball& ball) {
	noclip_effect_start = 0;
	ball.noclip = false;
}

void Powerup_manager::clear_shield_effect(Ball& ball) {
	shield_effect_start = 0;
	ball.shield_active = false;
}

void Powerup_manager::clear_ball_speed_effect(Ball& ball) {
	ball_speed_effect_start = 0;
	ball.speed /= config.ball_speed_effect_multiplier;
}

void Powerup_manager::clear_player_speed_effect(Player& player) {
	player_speed_effect_start = 0;
	player.speed /= config.player_speed_effect_multiplier;
}

void Powerup_manager::clear_invert_controls_effect(Player& player) {
	player.controls_inverted = false;
}

void Powerup_manager::clear_cannon_effect(Player& player) {
	player.cannon_active = false;
	last_shot = 0;
}

void Powerup_manager::clear_all_effects(Ball& ball, Player& player) {
	if(noclip_effect_start > 0) clear_noclip_effect(ball);
	if (shield_effect_start > 0) clear_shield_effect(ball);
	if (ball_speed_effect_start > 0) clear_ball_speed_effect(ball);
	if (player_speed_effect_start > 0) clear_player_speed_effect(player);
	if (invert_controls_effect_start > 0) clear_invert_controls_effect(player);
	if (cannon_effect_start > 0) clear_cannon_effect(player);
}