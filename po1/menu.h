#pragma once

#include "title.h"
#include "button.h"
#include "config.h"
#include "game.h"

#include <vector>

class Menu {
public:
	int x;
	int y;
	int title_x;
	int title_y;
	int pause_x;
	int pause_y;
	int start_x;
	int start_y;
	int back_x;
	int back_y;
	int mute_x;
	int mute_y;
	int width;
	int height;
	ALLEGRO_BITMAP* background;
	Title* title;
	Title* pause;
	Button* start;
	Button* back;
	Image_button* mute;

	Menu(ALLEGRO_FONT* title_font, ALLEGRO_FONT* button_font, ALLEGRO_FONT* button_font_hovered);
	~Menu();
	void update(unsigned int frame, Game& game);
	void render(const Game& game);
};