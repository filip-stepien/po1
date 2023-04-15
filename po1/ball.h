#pragma once
#include "allegro_includes.h"
#include "vector2.h"
#include "brick.h"
#include "player.h"
#include "game.h"
#include "points.h"
#include "config.h"

#include <vector>
#include <math.h>

class Ball {
public:
	double radius;
	double speed;
	int x; 
	int y;
	Brick* last_hit;
	Vector2 velocity;
	ALLEGRO_COLOR color;
	Game* game;
	Points* points;

	Ball(double radius, double speed, Game* game, Points* points);
	Ball(Game* game, Points* points);
	void move();
	void render();
	bool check_collision(const Brick* brick);
	bool check_collision(const Player& player);
	void handle_collision();
	void handle_collision(const Brick *brick);
	void handle_collision(std::vector<Brick*>& bricks);
	void handle_collision(const Player& player);
	void stick(const Player& player);
};

