#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <fstream>
#include <string>
#include <iostream>

class Points {
public:
	int counter;
	int best_score;
	int local_best;
	int initial_best;
	int x;
	int y;
	ALLEGRO_FONT* font;

	Points(ALLEGRO_FONT* font);
	~Points();
	void render();
	void update();
	void save();
};