#pragma once

#include "allegro_includes.h"
#include "config.h"

#include <iostream>

class Button {
public:
	int x;
	int y;
	int render_x;
	int render_y;
	int width;
	int height;
	int click_cooldown;
	unsigned int last_click_frame;
	const char* text;
	ALLEGRO_FONT* font;
	ALLEGRO_FONT* font_hovered;
	ALLEGRO_FONT* current_font;

	Button(int x, int y, const char* text, ALLEGRO_FONT* font, ALLEGRO_FONT* font_hovered);
	bool is_hovered();
	bool is_clicked();
	bool is_on_cooldown();
	void update(unsigned int frame);
	void render();
};