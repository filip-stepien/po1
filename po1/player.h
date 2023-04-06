#pragma once
#include "vector2.h"
#include "config.h"

class Player {
public:
	int width;
	int height;
	int top_x;
	int top_y;
	int bottom_x;
	int bottom_y;
	double speed;
	Vector2 velocity;

	Player(int width, int height, int x, int y, double speed);
	Player(struct Player_config config);
};