#include "brick.h"

Brick::Brick(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->color = config.soft_brick_color;
}

void Brick::render() {
	al_draw_filled_rectangle(x, y, x + width, y + height, color);
	al_draw_rectangle(x, y, x + width, y + height, al_map_rgb(0, 0, 0), 10);
}

void Brick::update() {
	should_break = true;
}

Brick_double::Brick_double(int x, int y, int width, int height) : Brick(x, y, width, height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->hit_count = 0;
	this->color = config.double_brick_color;
}

void Brick_double::update() {
	color = config.soft_brick_color;
	hit_count++;
	if (hit_count == 2)
		should_break = true;
}

Brick_solid::Brick_solid(int x, int y, int width, int height) : Brick(x, y, width, height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->color = config.solid_brick_color;
}

void Brick_solid::update() {
	should_break = false;
}