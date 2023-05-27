#include "ball.h"

constexpr double PI = 3.141592653589793238462643383279502884L;

Ball::Ball() {
	this->x = 0;
	this->y = 0;
	this->radius = config.ball_radius;
	this->speed = config.ball_speed;
	this->speed_cap = config.ball_speed * config.ball_speed_effect_multiplier;
	this->velocity = Vector2(-1, 1);
	this->last_hit = nullptr;
	this->noclip = false;
	this->shield_active = false;
	this->sprite = al_load_bitmap("ball.png");
}

void Ball::move() {
	velocity = velocity.normalized();
	velocity = velocity * speed;
	x += velocity.x;
	y += velocity.y;
}

void Ball::render() {
	if (sprite != nullptr)
		al_draw_bitmap(sprite, x - radius, y - radius, 0);
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

bool Ball::did_fall_down() {
	if (y - radius > config.window_height) {
		return true;
	}
	return false;
}

void Ball::handle_wall_collision(Sounds& sounds) {
	if (x > config.window_width - radius || x < radius) {
		velocity.x = -velocity.x;
		if (x > config.window_width - radius)
			x = config.window_width - radius;
		if (x < radius)
			x = radius;

		last_hit = nullptr;
	}

	if (y < radius) {
		velocity.y = -velocity.y;
		if (y > config.window_height - radius)
			y = config.window_height - radius;
		if (y < radius)
			y = radius;

		last_hit = nullptr;
	}

	if (shield_active && y + radius > config.shield_y) {
		velocity.y = -velocity.y;
		y = config.shield_y - radius;

		sounds.play_bounce();
	}
}

void Ball::collide(const Brick *brick) {
	if (noclip) return;

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

void Ball::stick(const Player& player) {
	x = player.x + player.width/2;
	y = player.y - radius;
}