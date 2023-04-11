#include "level.h"
#include "allegro_includes.h"
#include "brick.h"
#include <iostream>

Level::Level(int x, int y, int width, int height, int player_gap, Level::pattern map) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->player_gap = player_gap;
	this->map = map;
	
	x_count = map[0].size();
	y_count = map.size();

	brick_width = width / x_count;
	brick_height = (height - player_gap) / y_count;
}

Level::~Level() {
	for (auto brick : bricks) {
		delete brick;
	}

	bricks.clear();
}

void Level::init() {
	int x = this->x;
	int y = this->y;

	for (int i = 0; i < y_count; i++) { 
		for (int j = 0; j < x_count; j++) {

			switch (map[i][j]) {
				case 1:
					bricks.push_back(new Brick(x, y, brick_width, brick_height));
					break;
				case 2:
					bricks.push_back(new Brick_double(x, y, brick_width, brick_height));
					break;
				case 3:
					bricks.push_back(new Brick_solid(x, y, brick_width, brick_height));
					break;
			}

			x += brick_width;
		}
		x = this->x;
		y += brick_height;
	}
}

void Level::render() {
	for (auto brick : bricks) {
		brick->render();
	}
}