#pragma once

#include "level.h"
#include "level_patterns.h"

#include <vector>

class Level_manager {
public:
	int x;
	int y;
	int current_stage_number;
	int current_level_number;
	double stage_multiplier;
	std::vector<Level::pattern> patterns;
	Level* current_level;
	ALLEGRO_FONT* font;

	Level_manager(ALLEGRO_FONT* font);
	void load_next_level();
	void render_level_and_stage_number();
};