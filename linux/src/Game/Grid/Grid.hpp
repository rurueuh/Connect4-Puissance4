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

        void update();
        void draw(sf::RenderTarget &target);

        unsigned char checkWin(); // 0 = no win, 1 = player 1 win, 2 = player 2 win, 3 = draw

        token_t createToken(int x, int y, sf::Color color = sf::Color::White);
        void attackToken(int x, int y);
        void setToken(int x, int y, sf::Color color);
        void setTokenServer(int x, int y, sf::Color color);
        void setToken(token_t &token, sf::Color color);

    protected:
    private:
        std::array<std::array<token_t, 7>, 6> _grid;
        void networkToken(int x, int y, sf::Color color);
};
