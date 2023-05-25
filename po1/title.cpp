#include "title.h"

Title::Title(int x, int y, const char* text, ALLEGRO_FONT* font) {
	this->x = y;
	this->y = y;
	this->render_y = y;
	this->max_sway = config.max_sway;
	this->sway_frequency = config.sway_frequency;
	this->text = text;
	this->font = font;
}

void Title::update(unsigned int frame) {
	render_y = y + max_sway * sin(sway_frequency * frame);
}

void Title::render() {
	al_draw_text(font, al_map_rgb(255, 255, 255), x, render_y, 0, text);
}