/*
** EPITECH PROJECT, 2022
** linux
** File description:
** Network
*/

#include "Network.hpp"
#include "Game.hpp"

Network::Network()
{
    sf::Socket::Status status = this->_socket.connect("127.0.0.1", this->_port);
    if (status != sf::Socket::Done) {
        status = this->_socket.connect(this->_ip, this->_port + 1);
        if (status != sf::Socket::Done) {
            std::cout << "Error: " << status << std::endl;
            exit(84);
        }
    }
    sf::Packet packet;
    this->_socket.receive(packet);
    std::string str;
    packet >> str;
    if (str == "Red") {
        Game::getInstance()._player->setColor(sf::Color::Red);
        Game::getInstance()._player->setTurn(true);
    } else if (str == "Blue") {
        Game::getInstance()._player->setColor(sf::Color::Blue);
        Game::getInstance()._player->setTurn(false);
    } else {
        std::cout << "Error: " << str << std::endl;
        exit(84);
    }

    this->_thread = new sf::Thread(&Network::update, this);
    this->_thread->launch();
}

Network::~Network()
{
    this->_thread->terminate();
    delete this->_thread;
}

void Network::update()
{
    while (1) {
        if (Game::getInstance()._player->isTurn() == false) {
            this->receiveAttack();
        }
        sf::sleep(sf::milliseconds(100));
    }
}

void Network::sendAttack(int x, int y)
{
    sf::Packet packet;
    packet << x << y;
    this->_socket.send(packet);
}

void Network::receiveAttack()
{
    sf::Packet packet;
    this->_socket.receive(packet);
    int x;
    int y;
    packet >> x >> y;
    Game::getInstance()._grid->setTokenServer(x, y, (Game::getInstance()._player->getColor() == sf::Color::Red) ? sf::Color::Blue : sf::Color::Red);
    Game::getInstance()._player->setTurn(true);
}
