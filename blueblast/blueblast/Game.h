#pragma once

#include "SFML/Graphics.hpp"
#include "Utils.h"


struct Tile 
{
	enum class TileType { GRASS, WALL_VERTICAL, WALL_HORIZONTAL } tileType = Tile::TileType::GRASS;
	sf::Sprite spr;
};

struct Object
{
	enum class ObjectType { EMPTY, DISC, WIRE } objectType = Object::ObjectType::EMPTY;
	sf::Sprite spr;
};

struct Game
{
	enum class GameState { MAIN_MENU, INGAME, ENDSCREEN } gameState = GameState::MAIN_MENU;

	sf::Vector2f offset{ 25, 25 };
	bool moving = false;
	float elapsed = 0.0f;

	sf::Texture texGrass;
	sf::Texture texPlayer;
	sf::Texture texWall;
	sf::Texture texDisc;
	sf::Texture texHeart;
	sf::Texture tempTexEmpty;
	sf::Texture texBackgroundColor;
	sf::Texture texBackgroundFactory;

	sf::Sprite sprBackgroundColor;
	sf::Sprite sprBackgroundFactory;
	sf::Sprite sprHeart[3];
	sf::Sprite sprBackground;

	sf::Font arial;
	sf::Font kenvectorFuture;

	sf::Text gameNameText;
	sf::Text playGameText;

	Tile tile;

	void Init(); // Initialises the textures, sprites and 2D map
	void UpdateGame(float timer);
	void RenderGame(sf::RenderWindow& window);
	void RenderGameHud(sf::RenderWindow& window);

	sf::Vector2f MapToScrn(int x, int y);
	sf::Vector2i ScrnToMap(const sf::Vector2f& scrnPos);
};

/*
file - path and file name and extension
tex - set this up with the texture
*/
bool LoadTexture(const std::string& file, sf::Texture& tex);