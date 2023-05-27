#include "button.h"

Button::Button(int x, int y, const char* text, ALLEGRO_FONT* font, ALLEGRO_FONT* font_hovered) {
	this->x = x;
	this->y = y;
	this->render_x = x;
	this->render_y = y;
	this->click_cooldown = config.click_cooldown;
	this->last_click_frame = 0;
	this->text = text;
	this->font = font;
	this->font_hovered = font_hovered;
	this->current_font = font;
	this->visible = true;

	if (font != nullptr) {
		this->width = al_get_text_width(font, text);
		this->height = al_get_font_line_height(font);
	} else {
		this->width = -1;
		this->height = -1;
	}
}

bool Button::is_hovered() {
	ALLEGRO_MOUSE_STATE mouse;
	al_get_mouse_state(&mouse);

	if (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height) return true;
	return false;
}

bool Button::is_clicked() {
	ALLEGRO_MOUSE_STATE mouse;
	al_get_mouse_state(&mouse);

	bool hovered = is_hovered();
	bool left_clicked = mouse.buttons & 1;
	if (hovered && left_clicked) return true;

	return false;
}

bool Button::is_on_cooldown() {
	if (last_click_frame == 0) return false;
	return true;
}

void Button::update(unsigned int frame) {
	bool hovered = is_hovered();
	bool clicked = is_clicked();
	bool on_cooldown = is_on_cooldown();

	if (hovered) {
		int text_width = al_get_text_width(font, text);
		int hovered_text_width = al_get_text_width(font_hovered, text);
		int text_height = al_get_font_line_height(font);
		int hovered_text_height = al_get_font_line_height(font_hovered);

		int x_offset = (hovered_text_width - text_width) / 2;
		int y_offset = (hovered_text_height - text_height) / 2;

		current_font = font_hovered;
		render_x = x - x_offset;
		render_y = y - y_offset;
	}
	else {
		current_font = font;
		render_x = x;
		render_y = y;
	}

	if (clicked && !on_cooldown) {
		last_click_frame = frame;
	}

	if (frame >= last_click_frame + click_cooldown) {
		last_click_frame = 0;
	}
}

void Button::render() {
	if (!visible) return;

	al_draw_text(current_font, al_map_rgb(255, 255, 255), render_x, render_y, 0, text);
}

Image_button::Image_button(int x, int y, const char* background_down, const char* background_up) : Button(x, y, "", nullptr, nullptr) {
	this->x = x;
	this->y = y;
	this->render_x = x;
	this->render_y = y;
	this->background_on = al_load_bitmap(background_down);
	this->background_off = al_load_bitmap(background_up);
	this->width = al_get_bitmap_width(this->background_on);
	this->height = al_get_bitmap_height(this->background_on);
	this->on = true;
}

void Image_button::update(unsigned int frame, Sounds& sounds) {
	bool clicked = is_clicked();
	bool on_cooldown = is_on_cooldown();

	if (clicked && !on_cooldown) {
		last_click_frame = frame;
		on ? sounds.mute() : sounds.unmute();
		on = !on;
	}

	if (frame >= last_click_frame + click_cooldown) {
		last_click_frame = 0;
	}
}

void Image_button::render() {
	if (!visible) return;

	if(on) al_draw_bitmap(background_on, x, y, 0);
	else al_draw_bitmap(background_off, x, y, 0);
}