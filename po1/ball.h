#pragma once
#include "allegro_includes.h"
#include "vector2.h"
#include "player.h"
#include "brick.h"
#include "config.h"

#include <vector>
#include <cmath>

class Ball {
public:
	double radius;
	double speed;
	double speed_cap;
	int x; 
	int y;
	Brick* last_hit;
	Vector2 velocity;
	ALLEGRO_COLOR color;
	bool noclip;
	bool shield_active;
	ALLEGRO_BITMAP* sprite;

	Ball();
	void move();
	void render();
	bool check_collision(const Brick* brick);
	bool check_collision(const Player& player);
	bool did_fall_down();
	void handle_wall_collision();
	void collide(const Brick *brick);
	void collide(const Player& player);
	void stick(const Player& player);
};

