/*
** EPITECH PROJECT, 2022
** linux
** File description:
** Player
*/

#pragma once

#include "SFML.hpp"

class Player {
    public:
        Player();
        ~Player();

        sf::Color getColor() const { return this->_color; }
        bool isTurn() const { return this->_isTurn; }

        void setColor(sf::Color color) { this->_color = color; }
        void setTurn(bool isTurn) { this->_isTurn = isTurn; }

    protected:
    private:
        sf::Color _color = sf::Color::White;
        bool _isTurn = false;
};
