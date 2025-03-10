#pragma once

#include <SFML/Graphics.hpp>

struct Tile {
    enum class TileType { GRASS, WALL_VERTICAL, WALL_HORIZONTAL } tileType = Tile::TileType::GRASS;
    sf::Sprite* spr;
};
