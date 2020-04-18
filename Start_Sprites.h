#pragma once
#include <SFML/Graphics.hpp>
const sf::Vector2i Sprites_Hero[][27] = {
	{ sf::Vector2i(10, 33), sf::Vector2i(110, 33), sf::Vector2i(205, 33), sf::Vector2i(297, 33), sf::Vector2i(393, 33), sf::Vector2i(489, 33), sf::Vector2i(580, 33), sf::Vector2i(676, 33), sf::Vector2i(772, 33), sf::Vector2i(868, 33), sf::Vector2i(969, 33),  sf::Vector2i(10, 33), sf::Vector2i(110, 33), sf::Vector2i(205, 33), sf::Vector2i(297, 33), sf::Vector2i(393, 33), sf::Vector2i(489, 33), sf::Vector2i(580, 33), sf::Vector2i(676, 33), sf::Vector2i(772, 33), sf::Vector2i(868, 33), sf::Vector2i(969, 33), sf::Vector2i(10, 33), sf::Vector2i(110, 33), sf::Vector2i(205, 33), sf::Vector2i(297, 33), sf::Vector2i(393, 33)},
	{ sf::Vector2i(28, 215), sf::Vector2i(162, 215), sf::Vector2i(304, 215),sf::Vector2i(434, 215), sf::Vector2i(555, 215), sf::Vector2i(674, 215), sf::Vector2i(795, 215), sf::Vector2i(916, 215), sf::Vector2i(1031, 215), sf::Vector2i(28, 215), sf::Vector2i(162, 215), sf::Vector2i(304, 215),sf::Vector2i(434, 215), sf::Vector2i(555, 215), sf::Vector2i(674, 215), sf::Vector2i(795, 215), sf::Vector2i(916, 215), sf::Vector2i(1031, 215), sf::Vector2i(28, 215), sf::Vector2i(162, 215), sf::Vector2i(304, 215),sf::Vector2i(434, 215), sf::Vector2i(555, 215), sf::Vector2i(674, 215), sf::Vector2i(795, 215), sf::Vector2i(916, 215), sf::Vector2i(1031, 215)}
};

const int Sprites_Hero_Stay = 0;
const int Sprites_Hero_MoveRight = 1;
const int Sprites_Hero_MoveLeft = 2;
const int Sprites_Hero_Jump = 3;
const int Sprites_Hero_Fall = 4;
const int Sprites_Hero_FallEnd = 5;
