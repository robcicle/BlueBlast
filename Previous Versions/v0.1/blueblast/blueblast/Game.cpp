#include <assert.h>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace sf;
using namespace std;

vector<vector<Tile>> gameMap
{
	{ {Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS} },
	{ {Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS} },
	{ {Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL},{Tile::TileType::WALL} }
};

Vector2f Game::MapToScrn(int x, int y)
{
	Vector2f scrPos(offset.x + x * 64.f, offset.y + y * 64.f);
	return scrPos;
}

Vector2i Game::ScrnToMap(const Vector2f& scrnPos)
{
	Vector2i mapPos((int)(scrnPos.x - offset.x) / 64.f, (int)(scrnPos.y - offset.y) / 64.f);
	return mapPos;
}

bool LoadTexture(const string& file, Texture& tex)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(true);
		return true;
	}
	assert(true);
	return false;
}

// Snake that constantly moves around
struct Player {
	Sprite spr;
	enum class Heading { UP, DOWN, LEFT, RIGHT } heading = Heading::RIGHT;
} player;

void Game::Init()
{
	// Initialise for the textures
	LoadTexture("data/floor_tiles.png", texGarden);
	LoadTexture("data/robot.png", texPlayer);

	// Setting variables for the background of the level
	sprBackground.setTexture(texGarden);
	sprBackground.setTextureRect({ 74, 40, 32, 32 });
	sprBackground.setScale((float)GC::SCREEN_RES.x / 32, (float)GC::SCREEN_RES.y / 32);
	sprBackground.setPosition(0, 0);

	// Initialise the tiles within the map
	for (size_t y = 0; y < gameMap.size(); ++y)
		for (size_t x = 0; x < gameMap[y].size(); ++x)
		{
			Tile& t = gameMap[y][x];
			t.spr.setTexture(texGarden);
			if (t.tileType == Tile::TileType::GRASS)
				t.spr.setTextureRect({ 3, 40, 32, 32 });
			else if (t.tileType == Tile::TileType::WALL)
				t.spr.setTextureRect({ 74, 40, 32, 32 });
			t.spr.setScale(2, 2);
			t.spr.setPosition(offset.x + x * t.spr.getGlobalBounds().width,
				offset.y + y * t.spr.getGlobalBounds().height);
		}

	// Initialise the sprite for the player
	player.spr.setTexture(texPlayer);
	player.spr.setTextureRect(IntRect{ 4, 7, 44, 85 });
	player.spr.setScale(1, 0.75f);
	player.spr.setPosition(MapToScrn(1, 1));
}

void Game::UpdateGame(float timer)
{
	switch (gameState) 
	{
	case GameState::MAIN_MENU:
		break;
	case GameState::LEVEL1:
		elapsed += timer;
		// Get user input to change direction
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			player.heading = Player::Heading::UP;
			moving = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
		{
			player.heading = Player::Heading::DOWN;
			moving = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			player.heading = Player::Heading::LEFT;
			moving = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			player.heading = Player::Heading::RIGHT;
			moving = true;
		}

		if (elapsed >= 0.5f)
		{
			elapsed = 0;
			// Move regularly regardless of the input
			Vector2i mapPos = ScrnToMap(player.spr.getPosition());
			switch (player.heading)
			{
			case Player::Heading::LEFT:
				mapPos.x -= 1;
				break;
			case Player::Heading::RIGHT:
				mapPos.x += 1;
				break;
			case Player::Heading::UP:
				mapPos.y -= 1;
				break;
			case Player::Heading::DOWN:
				mapPos.y += 1;
				break;
			}

			// Allow the move if the new position is within bounds
			if (mapPos.y >= 0 && mapPos.x >= 0 && mapPos.x < (int)(gameMap[0].size() - 1) &&
				gameMap[mapPos.y][mapPos.x].tileType == Tile::TileType::GRASS && moving == true)
			{
				moving = false;
				player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
			}
		}
		break;
	case GameState::ENDSCREEN:
		break;
	}
	
}

void Game::RenderGame(RenderWindow& window)
{
	switch (gameState)
	{
	case GameState::MAIN_MENU:
		break;
	case GameState::LEVEL1:
		window.draw(sprBackground);
		// Draw garden
		for (size_t y = 0; y < gameMap.size(); ++y)
			for (size_t x = 0; x < gameMap[y].size(); ++x)
			{
				Tile& t = gameMap[y][x];
				window.draw(t.spr);
			}

		window.draw(player.spr);
		break;
	case GameState::ENDSCREEN:
		break;
	}
}