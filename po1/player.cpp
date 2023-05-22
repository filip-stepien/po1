#include "player.h"

Player::Player() {
	this->width = config.player_width;
	this->height = config.player_height;
	this->x = config.player_x;
	this->y = config.player_y;
	this->speed = config.player_speed;
	this->speed_cap = config.player_speed * config.player_speed_effect_multiplier;
	this->color = config.player_color;
	this->controls_inverted = false;

	moving_right = false;
	moving_left = false;
}

void Player::move_right() {

	if(x < config.window_width - width)
		controls_inverted ? x -= speed : x += speed;
}

void Player::move_left() {
	if(x > 0)
		controls_inverted ? x += speed : x -= speed;
}

void Player::render() {
	al_draw_filled_rectangle(x, y, x + width, y + height, color);
}