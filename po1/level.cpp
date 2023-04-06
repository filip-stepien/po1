#include "level.h"
#include "allegro_includes.h"
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

void Level::render() {
	int x = this->x;
	int y = this->y;

	for (int i = 0; i < y_count; i++) {
		for (int j = 0; j < x_count; j++) {
			if (map[i][j]) {
				al_draw_rectangle(
					x, 
					y, 
					x + brick_width, 
					y + brick_height, 
					al_map_rgb(255, 0, 0),
					2
				);
			}
			x += brick_width;
		}
		x = this->x;
		y += brick_height;
	}
}