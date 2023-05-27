#pragma once
#include "allegro_includes.h"
#include "config.h"

class Brick {
	public:
	int x;
	int y;
	int width;
	int height;
	bool should_break;
	ALLEGRO_BITMAP* sprite;

	Brick(int x, int y, int width, int height, const char* sprite);
	virtual void render();
	virtual void update();
};

class Brick_double : public Brick {
public:
	int hit_count;
	ALLEGRO_BITMAP* shield_sprite;

	Brick_double(int x, int y, int width, int height, const char* sprite);
	void update();
	void render();
};

class Brick_solid : public Brick {
public:
	ALLEGRO_BITMAP* shield_sprite;

	Brick_solid(int x, int y, int width, int height, const char* sprite);
	void update();
	void render();
};