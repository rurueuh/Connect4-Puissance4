/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** main
*/

#include "Game.hpp"

int main()
{
    Game &game = Game::getInstance();
    game.init();
    game.run();
    return 0;
}
