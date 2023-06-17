/**
 * @file menu.cpp
 * @brief Klasa menu gry
 */

#include "menu.h"

Menu::Menu(const Game& game) {
	this->x = 0;
	this->y = 0;
	this->title_x = config.window_width / 2 - al_get_text_width(game.title_font, "Arkanoid") / 2;
	this->title_y = 150;
	this->end_x = config.window_width / 2 - al_get_text_width(game.title_font, "Koniec") / 2;
	this->end_y = 150;
	this->pause_x = config.window_width / 2 - al_get_text_width(game.title_font, "Pauza") / 2;
	this->pause_y = 150;
	this->start_x = config.window_width / 2 - al_get_text_width(game.button_font, "START") / 2;
	this->start_y = 400;
	this->back_x = config.window_width / 2 - al_get_text_width(game.button_font, "KONTYNUUJ") / 2;
	this->back_y = 400;
	this->new_game_x = config.window_width / 2 - al_get_text_width(game.button_font, "NOWA GRA") / 2;
	this->new_game_y = 450;
	this->mute_x = 0;
	this->mute_y = 0;
	this->width = config.window_width;
	this->height = config.window_width;
	this->font = game.button_font;
	this->background = al_load_bitmap("background.png");
	this->title = new Title(title_x, title_y, "Arkanoid", game.title_font);
	this->end = new Title(end_x, end_y, "Koniec", game.title_font);
	this->pause = new Title(pause_x, pause_y, "Pauza", game.title_font);

	this->start = new Button(start_x, start_y, "START", game.button_font, game.button_font_hovered);
	this->back = new Button(back_x, back_y, "KONTYNUUJ", game.button_font, game.button_font_hovered);
	this->new_game = new Button(new_game_x, new_game_y, "NOWA GRA", game.button_font, game.button_font_hovered);

	this->mute = new Image_button(10, 542, "mute_on.png", "mute_off.png");

	pause->visible = false;
	back->visible = false;
	end->visible = false;
	new_game->visible = false;
}

Menu::~Menu() {
	delete title;
	delete pause;
	delete start;
	delete back;
	delete mute;
}

void Menu::update(unsigned int frame, Game& game, Sounds& sounds) {
	title->update(frame);
	pause->update(frame);
	start->update(frame);
	back->update(frame);
	mute->update(frame, sounds);
	end->update(frame);
	new_game->update(frame);

	if (start->visible && start->is_clicked() && !game.started) {
		game.started = true;
		sounds.play_option();
	}

	if (back->visible && back->is_clicked() && game.started && game.paused) {
		game.paused = false;
		sounds.play_option();
	}
	if (new_game->visible && new_game->is_clicked() && !game.started) {
		game.started = true;
		sounds.play_option();
	}
}

void Menu::render(int score) {
	title->render();
	pause->render();
	start->render();
	back->render();
	mute->render();
	end->render();
	new_game->render();

	if (end->visible) 
	al_draw_textf(
		font, 
		al_map_rgb(255, 255, 255), 
		config.window_width / 2, 
		title_y + 160, 
		ALLEGRO_ALIGN_CENTER, 
		"Wynik: %d", 
		score
	);
}