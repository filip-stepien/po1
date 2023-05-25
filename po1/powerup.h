#pragma once

#include "allegro_includes.h"
#include "vector2.h"
#include "ball.h"
#include "player.h"
#include "config.h"

#include <vector>
#include <iostream>

class Powerup {
public:
	using effects = enum effects { EFFECT_NOCLIP, EFFECT_SHIELD, EFFECT_BALL_SPEED, EFFECT_PLAYER_SPEED, EFFECT_INVERT_CONTROLS, EFFECT_CANNON };

	effects effect;
	double radius;
	double speed;
	int x;
	int y;
	Vector2 velocity;
	ALLEGRO_COLOR color;

	Powerup(int x, int y, effects effect);
	void move();
	void render();
	bool check_collision(const Player& player);
	virtual void collide(Ball& ball, Player& player);
	bool did_fall_down();
};

class Powerup_noclip : public Powerup {
public:
	Powerup_noclip(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};

class Powerup_shield : public Powerup {
public:
	Powerup_shield(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};

class Powerup_ball_speed : public Powerup {
public:
	Powerup_ball_speed(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};

class Powerup_player_speed : public Powerup {
public:
	Powerup_player_speed(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};

class Powerup_invert_controls : public Powerup {
public:
	Powerup_invert_controls(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};

class Powerup_cannon : public Powerup {
public:
	Powerup_cannon(int x, int y, effects effect);
	void collide(Ball& ball, Player& player);
};