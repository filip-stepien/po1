#include "points.h"

Points::Points(ALLEGRO_FONT* font) {
	this->x = config.points_x;
	this->y = config.points_y;
	this->width = config.points_width;
	this->height = config.points_height;
	this->counter = 0;
	this->font = font;
}

Points::Points(int x, int y, int width, int height, ALLEGRO_FONT* font) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->counter = 0;
	this->font = font;
}

void Points::render() {
	std::string points_string = "Wynik: ";
	points_string += std::to_string(counter);

	/*al_draw_rectangle(
		x,
		y,
		x + width,
		y + height,
		al_map_rgb(255, 255, 255),
		1
	);*/

	al_draw_text(
		font,
		al_map_rgb(255, 255, 255),
		x + width / 2,
		y + height / 2 - config.font_size / 2,
		ALLEGRO_ALIGN_CENTER,
		points_string.c_str()
	);
}