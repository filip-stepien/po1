#pragma once
#include <cmath>

class Vector2 {
public:
	double x;
	double y;

	Vector2();
	Vector2(double x, double y);
	Vector2 operator * (double num);
	Vector2 operator - ();

	Vector2 normalized();
};
