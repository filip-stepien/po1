#pragma once
#include "allegro_includes.h"
#include "config.h"

class Player {
public:
	int width;
	int height;
	int cannon_width;
	int cannon_height;
	int x;
	int y;
	double speed;
	double speed_cap;
	ALLEGRO_COLOR color;
	ALLEGRO_BITMAP* sprite;
	ALLEGRO_BITMAP* cannon_sprite;
	bool moving_right;
	bool moving_left;
	bool controls_inverted;
	bool cannon_active;

	Player();

	void render();
	void move_right();
	void move_left();
};