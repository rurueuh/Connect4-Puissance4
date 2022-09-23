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
    return token;
}

void Grid::setToken(int x, int y, sf::Color color)
{
    this->_grid[y][x].color = color;
}

void Grid::setToken(token_t &token, sf::Color color)
{
    token.color = color;
}

unsigned char Grid::checkWin()
{
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (this->_grid[i][j].color != sf::Color::White) {
                if (j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i][j + 1].color && this->_grid[i][j].color == this->_grid[i][j + 2].color && this->_grid[i][j].color == this->_grid[i][j + 3].color) {
                        return (this->_grid[i][j].color == sf::Color::Red ? 1 : 2);
                    }
                }
                if (i < 3) {
                    if (this->_grid[i][j].color == this->_grid[i + 1][j].color && this->_grid[i][j].color == this->_grid[i + 2][j].color && this->_grid[i][j].color == this->_grid[i + 3][j].color) {
                        return (this->_grid[i][j].color == sf::Color::Red ? 1 : 2);
                    }
                }
                if (i < 3 && j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i + 1][j + 1].color && this->_grid[i][j].color == this->_grid[i + 2][j + 2].color && this->_grid[i][j].color == this->_grid[i + 3][j + 3].color) {
                        return (this->_grid[i][j].color == sf::Color::Red ? 1 : 2);
                    }
                }
                if (i > 2 && j < 4) {
                    if (this->_grid[i][j].color == this->_grid[i - 1][j + 1].color && this->_grid[i][j].color == this->_grid[i - 2][j + 2].color && this->_grid[i][j].color == this->_grid[i - 3][j + 3].color) {
                        return (this->_grid[i][j].color == sf::Color::Red ? 1 : 2);
                    }
                }
            }
        }
    }
    return (0);
}

void Grid::draw()
{
    std::cout << "- - - - - - - -" << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (this->_grid[i][j].color == sf::Color::Red) {
                std::cout << "R";
            } else if (this->_grid[i][j].color == sf::Color::Blue) {
                std::cout << "B";
            } else {
                std::cout << "W";
            }
        }
        std::cout << std::endl;
    }
}
