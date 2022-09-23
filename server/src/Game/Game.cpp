/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _network = new Network();
    _grid = new Grid();
}

Game::~Game()
{
    delete _network;
    delete _grid;
}

void Game::run()
{
    while (1) {
        update();
        if (stop)
            break;
        sf::sleep(sf::milliseconds(100));
    }
}

static void updateFps(sf::Text &fps, sf::Clock &clock)
{
    static int frame = 0;
    static float time = 0;

    frame++;
    time += clock.restart().asSeconds();
    if (time >= 1) {
        fps.setString(std::to_string(frame));
        frame = 0;
        time = 0;
    }
}

void Game::update()
{
    this->_network->update();
    auto win = this->_grid->checkWin();
    if (win != 0) {
        std::cout << "Player " << (win == 1 ? "red" : "blue") << " win !" << std::endl;
        this->stop = true;
    }
    // updateFps(_fps, _clock);
}
