#pragma once
#include "vector2.h"

class Ball
{
public:
	double radius;
	double speed;
	int x, y;
	Vector2 velocity;

	Ball(int x, int y, double radius, double speed);
	void update();
	void render();
};

