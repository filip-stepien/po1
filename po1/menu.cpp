#include "menu.h"

Menu::Menu(ALLEGRO_FONT* title_font, ALLEGRO_FONT* button_font, ALLEGRO_FONT* button_font_hovered) {
	this->x = 0;
	this->y = 0;
	this->title_x = config.window_width / 2 - al_get_text_width(title_font, "Arkanoid") / 2;
	this->title_y = 150;
	this->pause_x = config.window_width / 2 - al_get_text_width(title_font, "Pauza") / 2;
	this->pause_y = 150;
	this->start_x = config.window_width / 2 - al_get_text_width(button_font, "START") / 2;
	this->start_y = 400;
	this->back_x = config.window_width / 2 - al_get_text_width(button_font, "KONTYNUUJ") / 2;
	this->back_y = 400;
	this->mute_x = 0;
	this->mute_y = 0;
	this->width = config.window_width;
	this->height = config.window_width;
	this->background = al_load_bitmap("background.png");
	this->title = new Title(title_x, title_y, "Arkanoid", title_font);
	this->pause = new Title(pause_x, pause_y, "Pauza", title_font);
	this->start = new Button(start_x, start_y, "START", button_font, button_font_hovered);
	this->back = new Button(back_x, back_y, "KONTYNUUJ", button_font, button_font_hovered);
	this->mute = new Image_button(10, 542, "mute_on.png", "mute_off.png");

	pause->visible = false;
	back->visible = false;
}

Menu::~Menu() {
	delete title;
	delete pause;
	delete start;
	delete back;
	delete mute;
}

void Menu::update(unsigned int frame, Game& game) {
	title->update(frame);
	pause->update(frame);
	start->update(frame);
	back->update(frame);
	mute->update(frame);

	if (start->is_clicked() && !game.started) game.started = true;
	if (back->is_clicked() && game.started && game.paused) game.paused = false;
}

void Menu::render(const Game& game) {
	title->render();
	pause->render();
	start->render();
	back->render();
	mute->render();
}