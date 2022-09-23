/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#pragma once

#include "SFML.hpp"
#include "Network.hpp"
#include "Grid.hpp"

class Game {
    public:
        Game();
        ~Game();

        // skeletron
        static Game &getInstance() {
            static Game instance;
            return instance;
        }

        void run();

        Network *_network;
        Grid *_grid;

        bool stop = false;

    protected:
    private:
        void update();

};
