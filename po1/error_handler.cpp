#include "error_handler.h"
#include "game.h"
#include <iostream>

Error_handler::Error_handler(Game* game)
{
    this->game = game;
}

int Error_handler::get_err_code() {
    if (!game->game_initialized) return 100;
    if (!game->keyboard_initialized) return 101;
    if (!game->primitive_shapes_addon_initialized) return 102;
    if (!game->font_addon_initialized) return 103;
    if (!game->display) return 104;
    if (!game->queue) return 105;
    if (!game->font) return 106;
    if (!game->timer) return 107;
    return 0;
}

bool Error_handler::get_err_state() {
    int code = get_err_code();
    return code == 0 ? false : true;
}

std::string Error_handler::get_err_msg() {
    int code = get_err_code();
    switch (code) {
    case 0:
        return "Gra dziala poprawnie";
    case 100:
        return "Niepoprawna inicjalizacja gry. Kod bledu: 100";
    case 101:
        return "Klawiatura nie zostala zainicjalizowana poprawnie. \nKod bledu: 101";
    case 102:
        return "Dodatek \"Primitive shapes\" nie zostal zainicjowany poprawnie. \nKod bledu: 102";
    case 103:
        return "Dodatek \"Font addon\" nie zostal zainicjowany poprawnie. \nKod bledu: 103";
    case 104:
        return "Okno nie zostalo zainicjalizowane poprawnie. \nKod bledu: 104";
    case 105:
        return "Kolejka nie zostala zainicjalizowana poprawnie. \nKod bledu: 105";
    case 106:
        return "Czcionka nie zostala zainicjalizowana poprawnie. \nKod bledu: 106";
    case 107:
        return "Licznik nie zostal zainicjalizowany poprawnie. \nKod bledu: 107";
    default:
        return "Niezidentyfikowany blad.";
    }
}
