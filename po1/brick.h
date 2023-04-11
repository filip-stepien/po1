#pragma once
#include "allegro_includes.h"

class Brick {
	public:
	int x;
	int y;
	int width;
	int height;
	bool should_break;
	ALLEGRO_COLOR color;

	Brick(int x, int y, int width, int height);
	virtual void render();
	virtual void update();
};

class Brick_double : public Brick {
public:
	int hit_count;

	Brick_double(int x, int y, int width, int height);
	void update();
};

class Brick_solid : public Brick {
public:
	Brick_solid(int x, int y, int width, int height);
	void update();
};