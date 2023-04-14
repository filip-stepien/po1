#pragma once

class Points {
public:
	int counter;
	int x;
	int y;
	int width;
	int height;
	ALLEGRO_FONT* font;

	Points(int x, int y, int width, int height, ALLEGRO_FONT* font);
	void render();
};