#include "level.h"

Level::Level(Level::pattern map) {
	this->x = 0;
	this->y = 0;
	this->width = config.window_width;
	this->height = config.window_height;
	this->player_gap = config.player_gap;
	this->map = map;
	this->solid_brick_count = 0;
}

Level::Level(int x, int y, int width, int height, int player_gap, Level::pattern map) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->player_gap = player_gap;
	this->map = map;
	this->solid_brick_count = 0;
}

Level::~Level() {
	for (auto brick : bricks) {
		delete brick;
	}

	bricks.clear();
}

void Level::reset() {
	int x = this->x;
	int y = this->y;
	int x_count = map[0].size();
	int y_count = map.size();
	int brick_width = width / x_count;
	int brick_height = (height - player_gap) / y_count;

	bricks.clear();
	solid_brick_count = 0;

	const char* brick_sprites[4] = { "brick0.png", "brick1.png", "brick2.png", "brick3.png" };
	int sprite_idx = 0;
	bool inserted;

	for (int i = 0; i < y_count; i++) {
		inserted = false;
		for (int j = 0; j < x_count; j++) {

			switch (map[i][j]) {
				case 1:
					bricks.push_back(new Brick(x, y, brick_width, brick_height, brick_sprites[rand() % 4]));
					inserted = true;
					break;
				case 2:
					bricks.push_back(new Brick_double(x, y, brick_width, brick_height, brick_sprites[rand() % 4]));
					inserted = true;
					break;
				case 3:
					bricks.push_back(new Brick_solid(x, y, brick_width, brick_height, brick_sprites[rand() % 4]));
					inserted = true;
					solid_brick_count++;
					break;
			}

			x += brick_width;
		}

		x = this->x;
		y += brick_height;

		if (inserted) sprite_idx++;
		if (sprite_idx == 3) sprite_idx = 0;
	}
}

void Level::render() {
	for (auto brick : bricks) {
		brick->render();
	}
}

bool Level::did_game_end() {
	if (bricks.size() == solid_brick_count) {
		return true;
	}
	return false;
}