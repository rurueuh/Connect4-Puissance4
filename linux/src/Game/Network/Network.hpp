/*
** EPITECH PROJECT, 2022
** linux
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

        void sendAttack(int x, int y);
        void receiveAttack();

    protected:
    private:
        sf::TcpSocket _socket;
        const sf::IpAddress _ip = "127.0.0.1";
        const unsigned short _port = 56565;
        sf::Thread *_thread;
};
