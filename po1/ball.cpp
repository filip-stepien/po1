#include "ball.h"
#include "config.h"
#include "vector2.h"
#include "allegro_includes.h"

#include <math.h>

constexpr double PI = 3.141592653589793238462643383279502884L;

Ball::Ball(int x, int y, double radius, double speed) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->speed = speed;
	this->velocity = Vector2(-1, 1);
	this->margin = 0.1f;
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
	}

	if (y > config.window_height - radius || y < radius) {
		velocity.y = -velocity.y;
		if (y > config.window_height - radius) 
			y = config.window_height - radius;
		if (y < radius)
			y = radius;
	}
}

void Ball::render()
{
	al_draw_circle(x, y, radius, al_map_rgb(255, 255, 255), 1);
}

bool Ball::check_collision(const Brick *brick) {
	if (x + radius > brick->x - brick->width * margin && x - radius < brick->x + brick->width * (1 + margin)
		&& y + radius > brick->y - brick->height * margin && y - radius < brick->y + brick->height * (1 + margin)) {
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
	if (x < brick->x) {
		velocity.x = -velocity.x;
		x = brick->x - radius - speed;
	}
	else if (x > brick->x + brick->width) {
		velocity.x = -velocity.x;
		x = brick->x + radius + brick->width + speed;
	}

	if (y < brick->y) {
		velocity.y = -velocity.y;
		y = brick->y - radius - speed;
	}
	else if (y > brick->y + brick->height) {
		velocity.y = -velocity.y;
		y = brick->y + radius + brick->height + speed;
	}
}

void Ball::collide(const Player& player) {
	double collision_point_interpolated = (x - (player.x + player.width / static_cast<double>(2))) / (player.width / static_cast<double>(2));
	double angle = collision_point_interpolated * (PI / static_cast<double>(3));

	velocity.x = speed * sin(angle);
	velocity.y = speed * cos(angle);

	velocity.y = -velocity.y;
}