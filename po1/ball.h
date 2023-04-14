#pragma once
#include "vector2.h"
#include "brick.h"
#include "player.h"

class Ball
{
public:
	double radius;
	double speed;
	int x, y;
	Brick* last_hit;
	Vector2 velocity;
	ALLEGRO_COLOR color;

	Ball(int x, int y, double radius, double speed);
	void update();
	void render();
	bool check_collision(const Brick* brick);
	bool check_collision(const Player& player);
	void collide(const Brick *brick);
	void collide(const Player& player);
};

