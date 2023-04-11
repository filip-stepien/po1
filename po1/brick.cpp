#include "brick.h"
#include "level.h"

Brick::Brick(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->color = al_map_rgb(150, 150, 150);
}

void Brick::render() {
	al_draw_filled_rectangle(x, y, x + width, y + height, color);
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
	this->color = al_map_rgb(255, 255, 255);
}

void Brick_double::update() {
	color = al_map_rgb(150, 150, 150);
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
	this->color = al_map_rgb(50, 50, 50);
}

void Brick_solid::update() {
	should_break = false;
}