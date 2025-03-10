#pragma once

#include <SFML/Graphics.hpp>

struct Object {
    enum class ObjectType { EMPTY, DISC, WIRE } objectType = Object::ObjectType::EMPTY;
    bool isVisible = true;
    sf::Sprite* spr;
};
