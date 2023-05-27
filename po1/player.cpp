#include "player.h"

Player::Player() {
	this->width = config.player_width;
	this->height = config.player_height;
	this->cannon_width = config.cannon_width;
	this->cannon_height = config.cannon_height;
	this->x = config.window_width / 2 - config.player_width / 2;
	this->y = config.player_y;
	this->speed = config.player_speed;
	this->speed_cap = config.player_speed * config.player_speed_effect_multiplier;
	this->controls_inverted = false;
	this->cannon_active = false;
	this->moving_right = false;
	this->moving_left = false;
	this->sprite = al_load_bitmap("player.png");
	this->cannon_sprite = al_load_bitmap("cannon.png");
}

void Player::move_right() {
	if(x < config.window_width - width)
	x += speed;
}

void Player::move_left() {
	if(x > 0)
	x -= speed;
}

void Player::render() {
	if (sprite != nullptr)
	al_draw_bitmap(sprite, x, y, 0);

	if(cannon_active && cannon_sprite != nullptr)
	al_draw_bitmap(cannon_sprite, x + width / 2 - cannon_width / 2, y - cannon_height, 0);
}

void Player::reset() {
	x = config.window_width / 2 - width / 2;
	y = config.player_y;
}