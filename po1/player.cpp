#include "player.h"

Player::Player() {
	this->width = config.player_width;
	this->height = config.player_height;
	this->cannon_width = config.cannon_width;
	this->cannon_height = config.cannon_height;
	this->x = config.player_x;
	this->y = config.player_y;
	this->speed = config.player_speed;
	this->speed_cap = config.player_speed * config.player_speed_effect_multiplier;
	this->color = config.player_color;
	this->controls_inverted = false;
	this->cannon_active = false;
	this->moving_right = false;
	this->moving_left = false;
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
	al_draw_filled_rectangle(x, y, x + width, y + height, color);

	if(cannon_active)
	al_draw_filled_rectangle(x + width / 2 - cannon_width / 2, y - height - cannon_height, x + width / 2 + cannon_width / 2, y, al_map_rgb(255, 0, 0));
}