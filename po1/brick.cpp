/**
 * @file brick.cpp
 * @brief Klasa cegiełki
 */

#include "brick.h"

Brick::Brick(int x, int y, int width, int height, const char* sprite) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->sprite = al_load_bitmap(sprite);
}

void Brick::render() {
	if (sprite != nullptr)
	al_draw_bitmap(sprite, x, y, 0);
}

void Brick::update() {
	should_break = true;
}

Brick_double::Brick_double(int x, int y, int width, int height, const char* sprite) : Brick(x, y, width, height, sprite) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->hit_count = 0;
	this->sprite = al_load_bitmap(sprite);
	this->shield_sprite = al_load_bitmap("brick_soft_shield.png");
}

void Brick_double::render() {
	if (sprite != nullptr)
	al_draw_bitmap(sprite, x, y, 0);

	if (shield_sprite != nullptr && hit_count == 0)
	al_draw_bitmap(shield_sprite, x, y, 0);
}

void Brick_double::update() {
	hit_count++;
	if (hit_count == 2)
		should_break = true;
}

Brick_solid::Brick_solid(int x, int y, int width, int height, const char* sprite) : Brick(x, y, width, height, sprite) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->should_break = false;
	this->sprite = al_load_bitmap(sprite);
	this->shield_sprite = al_load_bitmap("brick_solid_shield.png");
}

void Brick_solid::render() {
	if (sprite != nullptr)
	al_draw_bitmap(sprite, x, y, 0);

	if (shield_sprite != nullptr)
	al_draw_bitmap(shield_sprite, x, y, 0);
}

void Brick_solid::update() {
	should_break = false;
}