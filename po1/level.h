#pragma once
#include "allegro_includes.h"
#include "brick.h"
#include "config.h"

#include <vector>

class Level {
public:
	using pattern = std::vector<std::vector<int>>;

	int x;
	int y;
	int width;
	int height;
	int player_gap;
	int solid_brick_count;
	std::vector<Brick*> bricks;
	pattern map;
	
	Level(pattern map);
	Level(int x, int y, int width, int height, int player_gap, pattern map);
	~Level();
	void reset();
	void render();
	bool did_game_end();
};