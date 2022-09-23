/*
** EPITECH PROJECT, 2022
** server
** File description:
** Network
*/

#include "Network.hpp"
#include "Game.hpp"

Network::Network()
{
    if (_listener.listen(56565) != sf::Socket::Done) {
        std::cerr << "Error: Cannot listen on port 56565" << std::endl;
        _listener.listen(56566);
    } else {
        std::cout << "Server is listening on port 56565" << std::endl;
    }
    _listener.accept(_socket[0]);
    std::cout << "Client 1 connected" << std::endl;
    _listener.accept(_socket[1]);
    std::cout << "Client 2 connected" << std::endl;

    sf::Packet packet;
    packet << "Red";
    _socket[0].send(packet);

    packet.clear();
    packet << "Blue";
    _socket[1].send(packet);
}

Network::~Network()
{
}

void Network::update()
{
    sf::Packet packet;
    if (_socket[player_turn].receive(packet) == sf::Socket::Done) {
        sf::Vector2i pos;
        packet >> pos.x >> pos.y;
        std::cout << "Player " << (int) player_turn << " played at " << pos.x << " " << pos.y << std::endl;
        Game::getInstance()._grid->setToken(pos.x, pos.y, player_turn == 0 ? sf::Color::Red : sf::Color::Blue);
        player_turn = (player_turn + 1) % 2;

        sf::Packet packetReceiver;
        packetReceiver << pos.x << pos.y;
        std::cout << "Sending to player " << (int) player_turn << " attack" << std::endl;
        _socket[player_turn].send(packetReceiver);
    } else {
        std::cout << "Error receiving packet" << std::endl;

        exit(84);
    }
}
