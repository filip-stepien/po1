#include "ball.h"
#include "config.h"
#include "vector2.h"
#include "allegro_includes.h"

Ball::Ball(int x, int y, double radius, double speed) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->speed = speed;
	this->velocity = Vector2(2, 1);
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
