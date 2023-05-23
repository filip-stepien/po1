#include "points.h"

Points::Points(ALLEGRO_FONT* font) {
	this->x = 0;
	this->y = config.points_y;
	this->counter = 0;
	this->font = font;

	std::fstream save_file("score.save");

	if (save_file.is_open()) save_file >> this->best_score;
	else this->best_score = 0;

	save_file.close();
}

Points::~Points() {
	if (best_score > counter) {
		std::ofstream save_file("score.save", std::ios::out | std::ios::trunc);
		save_file << best_score;
		save_file.close();
	}
}

void Points::update() {
	if (best_score < counter) best_score++;
}

void Points::render() {
	al_draw_multiline_textf(
		font,
		al_map_rgb(255, 255, 255),
		x + config.window_width / 2,
		y,
		config.window_width,
		al_get_font_line_height(font),
		ALLEGRO_ALIGN_CENTER,
		"Wynik: %d\nNajlepszy: %d",
		counter,
		best_score
	);
}