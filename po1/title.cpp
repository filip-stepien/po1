﻿/**
 * @file title.cpp
 * @brief Klasa tytułu
 */

#include "title.h"

Title::Title(int x, int y, const char* text, ALLEGRO_FONT* font) {
	this->x = x;
	this->y = y;
	this->render_y = y;
	this->max_sway = config.max_sway;
	this->sway_frequency = config.sway_frequency;
	this->text = text;
	this->font = font;
	this->visible = true;
}

void Title::update(unsigned int frame) {
	if(visible)
	render_y = y + max_sway * sin(sway_frequency * frame);
}

void Title::render() {
	if(visible)
	al_draw_text(font, al_map_rgb(255, 255, 255), x, render_y, 0, text);
}