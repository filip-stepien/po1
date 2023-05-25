#pragma once

#include "vector2.h"
#include "brick.h"
#include "config.h"

class Shot {
public:
	int x;
	int y;
	int width;
	int height;
	Vector2 velocity;
	int speed;

	Shot(int x, int y);
	void move();
	void render();
	bool check_collision(Brick* brick);
};