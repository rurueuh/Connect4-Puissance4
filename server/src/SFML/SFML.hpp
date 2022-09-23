/*
** EPITECH PROJECT, 2022
** airplane
** File description:
** SFML
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <bits/stdc++.h>
#include "../../lib/lib.hpp"

typedef struct token_s {
    sf::Vector2f pos;
    sf::Color color = sf::Color::White;
} token_t;
