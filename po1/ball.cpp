#include "ball.h"
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
}

void Ball::render()
{
	al_draw_circle(x, y, radius, al_map_rgb(255, 255, 255), 1);
}
