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
	int end_x;
	int end_y;
	int pause_x;
	int pause_y;
	int start_x;
	int start_y;
	int back_x;
	int back_y;
	int new_game_x;
	int new_game_y;
	int mute_x;
	int mute_y;
	int width;
	int height;
	ALLEGRO_BITMAP* background;
	Title* title;
	Title* pause;
	Title* end;
	Button* start;
	Button* back;
	Button* new_game;
	Image_button* mute;
	ALLEGRO_FONT* font;

	Menu(const Game& game);
	~Menu();
	void update(unsigned int frame, Game& game);
	void render(int score);
};