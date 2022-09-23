/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#pragma once

#include "SFML.hpp"
#include "Grid.hpp"
#include "Player.hpp"
#include "../Network/Network.hpp"

class Game {
    public:
        Game();
        ~Game();

        // skeletron
        static Game &getInstance() {
            static Game instance;
            return instance;
        }

        sf::RenderWindow &getWindow() { return this->_window; }

        void init();
        void run();

        Grid *_grid;
        Player *_player;
        Network *_network;

    protected:
    private:
        void update();
        void draw();

        sf::Clock _clock;
        sf::Text _fps;
        sf::Font _font;

        sf::RenderWindow _window;
};
