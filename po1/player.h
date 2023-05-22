#pragma once
#include "allegro_includes.h"
#include "config.h"

class Player {
public:
	int width;
	int height;
	int x;
	int y;
	double speed;
	double speed_cap;
	ALLEGRO_COLOR color;
	bool moving_right;
	bool moving_left;
	bool controls_inverted;

	Player();

	void render();
	void move_right();
	void move_left();
};