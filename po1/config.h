#pragma once

struct Config {
    int window_width;
    int window_height;
    int font_size;
    int fps;
};

struct Player_config {
	int width;
	int height;
	int x;
	int y;
	double speed;
};

struct Ball_config {
	double radius;
	double speed;
	int x, y;
};

struct Level_config {
	int x_count;
	int y_count;
};