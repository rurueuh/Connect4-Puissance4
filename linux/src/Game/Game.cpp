/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
}

void Game::init()
{
    _window.create(sf::VideoMode(1920, 1080), "SPRITE CREATOR!");
    _window.setFramerateLimit(144);

    _font.loadFromFile("assets/font.ttf");

    _fps.setFont(_font);
    _fps.setCharacterSize(24);
    _fps.setFillColor(sf::Color::White);
    _fps.setPosition(10, 10);

    _grid = new Grid();
    _player = new Player();
    _network = new Network();
}

Game::~Game()
{
    delete _grid;
    delete _player;
    delete _network;
}

void Game::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
        update();
        draw();
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
    if (this->_window.hasFocus() == false)
        return;
    updateFps(_fps, _clock);
    _grid->update();
}

void Game::draw()
{
    _window.clear();
    _window.draw(_fps);
    _grid->draw(_window);
    _window.display();
}
