#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <iostream>
#include <cmath>

class Title {
public:
	int x;
	int y;
	int render_y;
	int max_sway;
	double sway_frequency;
	const char* text;
	ALLEGRO_FONT* font;

	Title(int x, int y, const char* text, ALLEGRO_FONT* font);
	void update(unsigned int frame);
	void render();
};