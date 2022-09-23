/*
** EPITECH PROJECT, 2022
** linux
** File description:
** Grid
*/

#include "Grid.hpp"
#include "Game.hpp"

Grid::Grid()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            this->_grid[i][j] = createToken(j, i);
        }
    }
}

Grid::~Grid()
{
}

token_t Grid::createToken(int x, int y, sf::Color color)
{
    token_t token;
    token.color = color;
    token.shape.setRadius(50);
    token.shape.setFillColor(color);
    token.shape.setPosition(x * 100, y * 100);
    return token;
}

void Grid::networkToken(int x, int y, sf::Color color)
{
    Game::getInstance()._player->setTurn(false);
    Game::getInstance()._network->sendAttack(x, y);
}

void Grid::setTokenServer(int x, int y, sf::Color color)
{
    this->_grid[y][x].color = color;
    this->_grid[y][x].shape.setFillColor(color);
}

void Grid::setToken(int x, int y, sf::Color color)
{
    this->_grid[y][x].color = color;
    this->_grid[y][x].shape.setFillColor(color);
    this->networkToken(x, y, color);
}

void Grid::setToken(token_t &token, sf::Color color)
{
    token.color = color;
    token.shape.setFillColor(color);
    this->networkToken(token.shape.getPosition().x / 100, token.shape.getPosition().y / 100, color);
}

void Grid::attackToken(int x, int y)
{
    if (this->_grid[y][x].color == sf::Color::White) {
        if (y != 5) {
            if (this->_grid[y + 1][x].color != sf::Color::White) {
                this->setToken(this->_grid[y][x], Game::getInstance()._player->getColor());
            }
        } else {
            this->setToken(this->_grid[y][x], Game::getInstance()._player->getColor());
        }
    }
}

unsigned char Grid::checkWin()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (this->_grid[i][j].color != sf::Color::White) {
                if (j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i][j + 1].color && this->_grid[i][j].color == this->_grid[i][j + 2].color && this->_grid[i][j].color == this->_grid[i][j + 3].color) {
                        return (this->_grid[i][j].color == Game::getInstance()._player->getColor() ? 1 : 2);
                    }
                }
                if (i < 3) {
                    if (this->_grid[i][j].color == this->_grid[i + 1][j].color && this->_grid[i][j].color == this->_grid[i + 2][j].color && this->_grid[i][j].color == this->_grid[i + 3][j].color) {
                        return (this->_grid[i][j].color == Game::getInstance()._player->getColor() ? 1 : 2);
                    }
                }
                if (i < 3 && j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i + 1][j + 1].color && this->_grid[i][j].color == this->_grid[i + 2][j + 2].color && this->_grid[i][j].color == this->_grid[i + 3][j + 3].color) {
                        return (this->_grid[i][j].color == Game::getInstance()._player->getColor() ? 1 : 2);
                    }
                }
                if (i > 2 && j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i - 1][j + 1].color && this->_grid[i][j].color == this->_grid[i - 2][j + 2].color && this->_grid[i][j].color == this->_grid[i - 3][j + 3].color) {
                        return (this->_grid[i][j].color == Game::getInstance()._player->getColor() ? 1 : 2);
                    }
                }
            }
        }
    }
    return (0);
}

void Grid::update()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Game::getInstance()._player->isTurn()) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(Game::getInstance().getWindow());
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (this->_grid[i][j].shape.getGlobalBounds().contains(mousePosF)) {
                    this->attackToken(j, i);
                }
            }
        }
    }
    unsigned char win = this->checkWin();
    if (win != 0) {
        if (win == 3) {
            std::cout << "Draw" << std::endl;
        } else {
            if (win == 1) {
                std::cout << "You win" << std::endl;
            } else {
                std::cout << "You lose" << std::endl;
            }
        }
        Game::getInstance().getWindow().close();
    }
}

void Grid::draw(sf::RenderTarget &target)
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            target.draw(_grid.at(i).at(j).shape);
        }
    }
}
