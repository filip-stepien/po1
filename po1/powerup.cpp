#pragma once

#include "powerup.h"

Powerup::Powerup(int x, int y, const char* sprite, effects effect) {
	this->radius = config.powerup_radius;
	this->speed = config.powerup_speed;
	this->x = x;
	this->y = y;
	this->velocity = Vector2(0, 1);
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);

	velocity = velocity.normalized();
	velocity = velocity * speed;
}

void Powerup::move() {
	x += velocity.x;
	y += velocity.y;
}

void Powerup::render() {
	if(sprite != nullptr)
	al_draw_bitmap(sprite, x - radius, y - radius, 0);
}

bool Powerup::check_collision(const Player& player) {
	if (x + radius > player.x && x - radius < player.x + player.width
		&& y + radius > player.y && y - radius < player.y + player.height) {
		return true;
	}
	return false;
}

void Powerup::collide(Ball& ball, Player& player) {
	return;
}

bool Powerup::did_fall_down() {
	if (y - radius > config.window_height) {
		return true;
	}
	return false;
}

Powerup_noclip::Powerup_noclip(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_noclip::collide(Ball& ball, Player& player) {
	ball.noclip = true;
}

Powerup_shield::Powerup_shield(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_shield::collide(Ball& ball, Player& player) {
	ball.shield_active = true;
}

Powerup_ball_speed::Powerup_ball_speed(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_ball_speed::collide(Ball& ball, Player& player) {
	if (ball.speed < ball.speed_cap)
	ball.speed *= config.ball_speed_effect_multiplier;
}

Powerup_player_speed::Powerup_player_speed(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_player_speed::collide(Ball& ball, Player& player) {
	if (player.speed > player.speed_cap) 
	player.speed *= config.player_speed_effect_multiplier;
}

Powerup_invert_controls::Powerup_invert_controls(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_invert_controls::collide(Ball& ball, Player& player) {
	player.controls_inverted = true;
}

Powerup_cannon::Powerup_cannon(int x, int y, const char* sprite, effects effect) : Powerup(x, y, sprite, effect) {
	this->x = x;
	this->y = y;
	this->effect = effect;
	this->sprite = al_load_bitmap(sprite);
}

void Powerup_cannon::collide(Ball& ball, Player& player) {
	player.cannon_active = true;
}
