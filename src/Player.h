#pragma once

#include "SFML/Graphics.hpp"
#include "Tile.h"
#include "Object.h"

class Player
{
private:
    sf::Sprite* sprite;
    sf::Sprite* damage;
    float stunnedTimer = 0.0f;
    bool moving = false;
    bool stunned = false;
    int discs = 0;
    int health = 3;

public:
    enum class Heading { UP, DOWN, LEFT, RIGHT };
    Heading heading = Heading::RIGHT;

    Player(sf::Sprite* sprite, sf::Sprite* damageSprite)
        : sprite(sprite), damage(damageSprite) {
    }

    void SetMovement();

    sf::Vector2i Move(std::vector<std::vector<Tile>>& gameMap, std::vector<std::vector<Object>>& curObjMap, sf::Vector2f offset, sf::Vector2i mapPosition);

    void UpdateStunned(float elapsed);


    void Reset();

    int GetDiscs() const { return discs; }
    int GetHealth() const { return health; }
    bool IsStunned() const { return stunned; }

    sf::Sprite* GetPlayerSprite() const { return sprite; }
    sf::Sprite* GetDamageSprite() const { return damage; }
};