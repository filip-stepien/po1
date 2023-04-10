#pragma once
#include <vector>
#include "brick.h"

class Level {
public:
	using pattern = std::vector<std::vector<int>>;

	int x;
	int y;
	int width;
	int height;
	int x_count;
	int y_count;
	int brick_width;
	int brick_height;
	int player_gap;
	std::vector<Brick> bricks;
	pattern map;

	Level(int x, int y, int width, int height, int player_gap, pattern map);
	void init();
	void update();
	void render();
};