/*
** EPITECH PROJECT, 2022
** server
** File description:
** Network
*/

#pragma once

#include "SFML.hpp"

class Network {
    public:
        Network();
        ~Network();

        void update();

    protected:
    private:
        sf::TcpListener _listener;
        std::array<sf::TcpSocket, 2> _socket;
        unsigned char player_turn = 0; // 0 = Red, 1 = Blue
};
