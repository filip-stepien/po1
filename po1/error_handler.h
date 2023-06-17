/**
 * @file error_handler.h
 * @brief Klasa obsługi błędów
 */

#pragma once
#include "game.h"
#include <iostream>

/**
 * @brief Klasa obsługi błędów
 */
class Error_handler {
private:
    //! obiekt gry
    Game* game;

public:
    /**
     * @brief Konstruktor klasy obsługi błędów
     * @param game obiekt gry
     */
    Error_handler(Game* game);

    /**
    * @brief Generacja kodu błędu przy uruchomieniu gry
    * @return kod błędu uruchomienia
    */
    int get_err_code();

    /**
    * @brief Sprawdzenie czy wystąpił błąd
    * @return czy wystąpił błąd
    */
    bool get_err_state();

    /**
    * @brief Generacja wiadomości błędu
    * @return wiadomość błędu
    */
    std::string get_err_msg();
};