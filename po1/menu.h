/**
 * @file menu.h
 * @brief Klasa menu gry
 */

#pragma once

#include "title.h"
#include "button.h"
#include "config.h"
#include "game.h"
#include "sounds.h"

#include <vector>


/**
 * @brief Klasa menu gry
 */
class Menu {
public:
	//! koordynata X, od której będzie rysowane menu
	int x;
	//! koordynata Y, od której będzie rysowane menu
	int y;
	//! koordynata X, od której będzie rysowany tytuł menu
	int title_x;
	//! koordynata Y, od której będzie rysowany tytuł menu
	int title_y;
	//! koordynata X, od której będzie rysowany tytuł końca gry
	int end_x;
	//! koordynata y, od której będzie rysowany tytuł końca gry
	int end_y;
	//! koordynata X, od której będzie rysowany tytuł pauzy
	int pause_x;
	//! koordynata Y, od której będzie rysowany tytuł pauzy
	int pause_y;
	//! koordynata X, od której będzie rysowany tytuł nowej gry
	int start_x;
	//! koordynata Y, od której będzie rysowany tytuł nowej gry
	int start_y;
	//! koordynata X, od której będzie rysowany tytuł powrotu do gry
	int back_x;
	//! koordynata Y, od której będzie rysowany tytuł powrotu do gry
	int back_y;
	//! koordynata X, od której będzie rysowany przycisk nowej gry
	int new_game_x;
	//! koordynata Y, od której będzie rysowany przycisk nowej gry
	int new_game_y;
	//! koordynata X, od której będzie rysowany przycisk wyciszenia dźwięku
	int mute_x;
	//! koordynata Y, od której będzie rysowany przycisk wyciszenia dźwięku
	int mute_y;
	//! szerokość
	int width;
	//! wysokość
	int height;
	//! tło menu
	ALLEGRO_BITMAP* background;
	//! tytuł gry
	Title* title;
	//! tytuł pauzy
	Title* pause;
	//! tytuł końca gry
	Title* end;
	//! przycisk startu gry
	Button* start;
	//! przycisk powrotu do gry
	Button* back;
	//! przycisk nowej gry
	Button* new_game;
	//! przycisk wyciszenia dźwięków
	Image_button* mute;
	//! czcionka
	ALLEGRO_FONT* font;

	/**
	 * @brief Konstruktor klasy menu gry
	 * @param game obiekt gry
	 */
	Menu(const Game& game);

	/**
	 * @brief Destruktor klasy menu gry
	 */
	~Menu();

	/**
	 * @brief Aktualizacja stanu menu
	 * @param frame obecna klatka gry
	 * @param game obiekty gry
	 * @param sounds dźwięki gry
	 */
	void update(unsigned int frame, Game& game, Sounds& sounds);

	/**
	 * @brief Rysowanie menu
	 * @param score obecny wynik
	 */
	void render(int score);
};