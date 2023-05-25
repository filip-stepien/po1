#pragma once

#include "title.h"

class Popup {
public:
	int x;
	int y;
	int width;
	int height;
	Title title;

	void update();
	void render();
};