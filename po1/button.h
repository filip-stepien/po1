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
	bool visible;
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

class Image_button : public Button {
public:
	ALLEGRO_BITMAP* background_on;
	ALLEGRO_BITMAP* background_off;
	bool on;

	Image_button(int x, int y, const char* background_down, const char* background_up);
	void update(unsigned int frame);
	void render();
};