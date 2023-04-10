#pragma once
#include "config.h"

class Player {
public:
	int width;
	int height;
	int x;
	int y;
	double speed;
	bool moving_right;
	bool moving_left;

	Player(int width, int height, int x, int y, double speed);

	void render();
	void move_right();
	void move_left();
};