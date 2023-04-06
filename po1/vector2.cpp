#include "vector2.h"
#include "math.h"

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator * (double num) {
	return Vector2(x * num, y * num);
}

Vector2 Vector2::operator - () {
	return Vector2(-x, -y);
}

Vector2 Vector2::normalized() {
	double len = sqrt(x * x + y * y);
	return Vector2(x / len, y / len);
}

