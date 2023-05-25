#include "shot.h"

Shot::Shot(int x, int y) {
	this->x = x;
	this->y = y;
	this->width = config.shot_width;
	this->height = config.shot_height;
	this->velocity = Vector2(0, -1);
	this->speed = config.shot_speed;

	velocity = velocity.normalized();
	velocity = velocity * speed;
}

void Shot::move() {
	x += velocity.x;
	y += velocity.y;
}

void Shot::render() {
	al_draw_filled_rectangle(x, y, x + width, y + height, al_map_rgb(255, 255, 0));
}

bool Shot::check_collision(Brick* brick) {
	if (x > brick->x && x < brick->x + brick->width &&
		y > brick->y && y < brick->y + brick->height) {
		return true;
	}
	return false;
}