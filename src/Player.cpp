#pragma once

#include "Player.h"

void Player::SetMovement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		heading = Heading::UP;
		moving = true;
		return;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		heading = Heading::DOWN;
		moving = true;
		return;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		heading = Heading::LEFT;
		moving = true;
		return;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		heading = Heading::RIGHT;
		moving = true;
		return;
	}

	moving = false;
}

sf::Vector2i Player::Move(std::vector<std::vector<Tile>>& gameMap, std::vector<std::vector<Object>>& curObjMap, sf::Vector2f offset, sf::Vector2i mapPos)
{
	if (!moving || stunned)
		return mapPos;

	sf::Vector2i originalPos = mapPos;

	switch (heading) {
	case Heading::LEFT:  mapPos.x -= 1; break;
	case Heading::RIGHT: mapPos.x += 1; break;
	case Heading::UP:    mapPos.y -= 1; break;
	case Heading::DOWN:  mapPos.y += 1; break;
	}

	// Bounds Check
	if (mapPos.y < 0 || mapPos.x < 0 || mapPos.x >= (int)gameMap[0].size())
		return originalPos;

	// Ensure the tile is passable
	if (gameMap[mapPos.y][mapPos.x].tileType != Tile::TileType::GRASS)
		return originalPos;

	// Handle object interactions
	if (curObjMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::DISC) {
		curObjMap[mapPos.y][mapPos.x].objectType = Object::ObjectType::EMPTY;
		discs++;
	}
	else if (curObjMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::WIRE) {
		stunned = true;
		stunnedTimer = 0.f;
		health--;
		damage->setScale(sf::Vector2f(1, 1));
	}

	moving = false;

	return mapPos;
}

void Player::UpdateStunned(float elapsed)
{
	if (!stunned) return;

	stunnedTimer += elapsed;
	if (stunnedTimer >= 2.f) {
		stunned = false;
		stunnedTimer = 0.f;
		damage->setScale(sf::Vector2f(0, 0));
	}
}

void Player::Reset() {
	stunnedTimer = 0.0f;
	moving = false;
	stunned = false;
	discs = 0;
	health = 3;
	heading = Heading::RIGHT;
}