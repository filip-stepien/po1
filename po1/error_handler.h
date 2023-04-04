#pragma once
#include "game.h"
#include <iostream>

class Error_handler {
private:
    Game* game;

public:
    Error_handler(Game* game);
    int get_err_code();
    bool get_err_state();
    std::string get_err_msg();
};