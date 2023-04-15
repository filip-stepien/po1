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
	ALLEGRO_COLOR color;
	bool moving_right;
	bool moving_left;

	Player();
	Player(int x, int y, int width, int height, double speed);

	void render();
	void move_right();
	void move_left();
};