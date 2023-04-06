#include "player.h"

Player::Player(int width, int height, int x, int y, double speed) {
	this->width = width;
	this->height = height;
	this->top_x = x;
	this->top_y = y;
	this->bottom_x = x + width;
	this->bottom_y = y + height;
	this->speed = speed;
	this->velocity = Vector2(0, 0);
}

Player::Player(struct Player_config config) {
	this->width = config.width;
	this->height = config.height;
	this->top_x = config.x;
	this->top_y = config.y;
	this->bottom_x = config.x + config.width;
	this->bottom_y = config.y + config.height;
	this->speed = config.speed;
	this->velocity = Vector2(0, 0);
}