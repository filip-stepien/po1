/**
 * @file points.cpp
 * @brief Klasa licznika wyniku
 */

#include "points.h"

Points::Points(ALLEGRO_FONT* font) {
	this->x = 0;
	this->y = config.text_y;
	this->counter = 0;
	this->local_best = 0;
	this->font = font;

	std::fstream save_file("score.save");

	if (save_file.is_open()) {
		save_file >> this->best_score;
		save_file >> this->initial_best;
	} else {
		this->best_score = 0;
		this->initial_best = 0;
	}

	save_file.close();
}

Points::~Points() {
	if (best_score > initial_best) {
		std::ofstream save_file("score.save", std::ios::out | std::ios::trunc);
		save_file << best_score;
		save_file.close();
	}
}

void Points::update() {
	if (best_score < counter) best_score++;
}

void Points::render() {
	al_draw_textf(
		font,
		al_map_rgb(255, 255, 255),
		x + config.window_width / 2,
		y,
		ALLEGRO_ALIGN_CENTER,
		"Wynik: %d",
		counter
	);

	al_draw_textf(
		font,
		al_map_rgb(255, 255, 255),
		x + config.window_width / 2,
		y + al_get_font_line_height(font) + config.text_leading,
		ALLEGRO_ALIGN_CENTER,
		"Najlepszy: %d",
		best_score
	);
}

void Points::save() {
	std::ofstream save_file("score.save", std::ios::out | std::ios::trunc);
	save_file << counter;
	save_file.close();
}