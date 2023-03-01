#pragma once

#include "SFML/Graphics.hpp"
#include "Utils.h"


struct Tile 
{
	enum class TileType { GRASS, WALL } tileType = Tile::TileType::GRASS;
	sf::Sprite spr;
};

struct Game
{
	enum class GameState { MAIN_MENU, LEVEL1, ENDSCREEN } gameState = GameState::LEVEL1;

	sf::Vector2f offset{ 25, 25 };
	bool moving = false;
	float elapsed = 0.0f;
	sf::Texture texGarden;
	sf::Texture texPlayer;
	sf::Sprite sprBackground;
	Tile tile;

	void Init(); // Initialises the textures, sprites and 2D map
	void UpdateGame(float timer);
	void RenderGame(sf::RenderWindow& window);

	sf::Vector2f MapToScrn(int x, int y);
	sf::Vector2i ScrnToMap(const sf::Vector2f& scrnPos);
};

/*
file - path and file name and extension
tex - set this up with the texture
*/
bool LoadTexture(const std::string& file, sf::Texture& tex);