#include "player.h"

Player::Player(int x, int y, int width, int height, double speed) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->speed = speed;
	this->color = config.player_color;

	moving_right = false;
	moving_left = false;
}

Player::Player() {
	this->width = config.player_width;
	this->height = config.player_height;
	this->x = config.player_x;
	this->y = config.player_y;
	this->speed = config.player_speed;
	this->color = config.player_color;

	moving_right = false;
	moving_left = false;
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
}