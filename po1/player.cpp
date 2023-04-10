#include "player.h"
#include "allegro_includes.h"

Player::Player(int width, int height, int x, int y, double speed) {
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->speed = speed;

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
	al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(255, 255, 255));
}