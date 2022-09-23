/*
** EPITECH PROJECT, 2022
** linux
** File description:
** Grid
*/

#pragma once

#include "SFML.hpp"

class Grid {
    public:
        Grid();
        ~Grid();

        void draw();
        unsigned char checkWin(); // 0 = no win, 1 = red win, 2 = blue win

        token_t createToken(int x, int y, sf::Color color = sf::Color::White);
        void setToken(int x, int y, sf::Color color);
        void setToken(token_t &token, sf::Color color);

    protected:
    private:
        std::array<std::array<token_t, 7>, 6> _grid;
};
