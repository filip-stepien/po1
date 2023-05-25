#include "level_manager.h"

Level_manager::Level_manager(ALLEGRO_FONT* font) {
	this->x = 0;
	this->y = config.text_y + al_get_font_line_height(font) * 2;
	this->current_stage_number = 1;
	this->current_level_number = -1;
	this->stage_multiplier = 1;
	this->patterns = pattern_list;
	this->font = font;
	this->current_level = nullptr;
}

void Level_manager::load_next_level() {
	if (current_level_number == patterns.size() - 1) {
		current_level_number = -1;
		current_stage_number++;
	}

	current_level_number++;
	Level* selected_level = new Level(patterns[current_level_number]);
	current_level = selected_level;
}

void Level_manager::render_level_and_stage_number() {
	al_draw_textf(
		font, 
		al_map_rgb(255, 255, 255), 
		x + config.window_width / 2,
		y + config.text_leading * 2,
		ALLEGRO_ALIGN_CENTER, 
		"Poziom: %d - %d", 
		current_stage_number,
		current_level_number + 1
	);
}