#include "ball.h"
#include "config.h"
#include "vector2.h"
#include "allegro_includes.h"

#include <math.h>

#include <iostream>

constexpr double PI = 3.141592653589793238462643383279502884L;

Ball::Ball(int x, int y, double radius, double speed) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->speed = speed;
	this->velocity = Vector2(-1, 1);
	this->last_hit = nullptr;
	this->color = al_map_rgb(255, 255, 255);
}

void Ball::update()
{
	velocity = velocity.normalized();
	velocity = velocity * speed;
	x += velocity.x;
	y += velocity.y;

	if (x > config.window_width - radius || x < radius) {
		velocity.x = -velocity.x;
		if (x > config.window_width - radius)
			x = config.window_width - radius;
		if (x < radius)
			x = radius;
		
		last_hit = nullptr;
	}

	if (y > config.window_height - radius || y < radius) {
		velocity.y = -velocity.y;
		if (y > config.window_height - radius) 
			y = config.window_height - radius;
		if (y < radius)
			y = radius;

		last_hit = nullptr;
	}
}

void Ball::render()
{
	al_draw_filled_circle(x, y, radius, color);
}

bool Ball::check_collision(const Brick *brick) {
	if (x + radius > brick->x && x - radius < brick->x + brick->width &&
		y + radius > brick->y && y - radius < brick->y + brick->height) {
		return true;
	}
	return false;
}

bool Ball::check_collision(const Player& player) {
	if (x + radius > player.x && x - radius < player.x + player.width
		&& y + radius > player.y && y - radius < player.y + player.height) {
		return true;
	}
	return false;
}

void Ball::collide(const Brick *brick) {
	if (x < brick->x || x > brick->x + brick->width) {
		velocity.x = -velocity.x;
	}
	else {
		velocity.y = -velocity.y;
	}
}

void Ball::collide(const Player& player) {
	double collision_point_interpolated = (x - (player.x + player.width / static_cast<double>(2))) / (player.width / static_cast<double>(2));
	double angle = collision_point_interpolated * (PI / static_cast<double>(3));

	velocity.x = speed * sin(angle);
	velocity.y = speed * cos(angle);

	velocity.y = -velocity.y;
	last_hit = nullptr;
}