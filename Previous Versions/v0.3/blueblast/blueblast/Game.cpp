#include <assert.h>
#include <sstream>
#include <iomanip>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Utils.h"
#include "Game.h"

using namespace sf;
using namespace std;

vector<vector<Tile>> gameMap
{
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS} },
	{ {Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL} }
};

vector<vector<Object>> objMap
{
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
};

Vector2f Game::MapToScrn(int x, int y)
{
	Vector2f scrPos(offset.x + x * 64.f, offset.y + y * 64.f);
	return scrPos;
}

Vector2i Game::ScrnToMap(const Vector2f& scrnPos)
{
	Vector2i mapPos((int)(scrnPos.x - offset.x) / 64, (int)(scrnPos.y - offset.y) / 64);
	return mapPos;
}

Text CentreText(Text text) 
{
	Vector2f textCentre;
	FloatRect textRect;

	// Setting the origin to the centre
	textRect = text.getGlobalBounds();
	textCentre.x = textRect.width / 2.0f;
	textCentre.y = textRect.height / 2.0f;
	text.setOrigin(textCentre);

	return text;
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

// Player struct to hold information
struct Player {
	Sprite spr;
	Sprite damage;
	float stunnedTimer = 0.0f;
	bool stunned = false;
	int discs = 0;
	int health = 3;
	enum class Heading { UP, DOWN, LEFT, RIGHT } heading = Heading::RIGHT;
} player;

void Game::Init()
{
	// Initialise for the textures and fonts
	LoadTexture("data/grass.png", texGrass);
	LoadTexture("data/wall_tiles.png", texWall);
	LoadTexture("data/robot.png", texPlayer);
	LoadTexture("data/heart.png", texHeart);
	LoadTexture("data/bg1.png", texBackgroundColor);
	LoadTexture("data/bg2.png", texBackgroundFactory);
	LoadTexture("data/disc.png", texDisc);
	LoadTexture("data/wire.png", texWire);
	LoadTexture("data/empty.png", tempTexEmpty);
	LoadTexture("data/electrocute.png", texElectrocute);
	if (!kenvectorFuture.loadFromFile("data/kenvector_future.ttf"))
		assert(false);
	if (!arial.loadFromFile("data/arial.ttf"))
		assert(false);

	// Setting variables for the background of the main menu
	sprBackgroundColor.setTexture(texBackgroundColor);
	sprBackgroundFactory.setTexture(texBackgroundFactory);
	sprBackgroundFactory.setTextureRect({ 0, 0, 272, 104 });
	sprBackgroundColor.scale((float)GC::SCREEN_RES.x / 272.f, (float)GC::SCREEN_RES.y / 160.f);
	sprBackgroundFactory.scale((float)GC::SCREEN_RES.x / 272.f, (float)GC::SCREEN_RES.y / 160.f);
	sprBackgroundColor.setPosition(0, 0);
	sprBackgroundFactory.setPosition(0, 280);

	// Setting variables for the background of the level
	sprBackground.setTexture(texWall);
	sprBackground.setTextureRect({ 0, 184, 64, 64 });
	sprBackground.setScale((float)GC::SCREEN_RES.x / 60.f, (float)GC::SCREEN_RES.y / 60.f);
	sprBackground.setPosition(0, 0);

	// Title name text and styling
	gameNameText.setFont(kenvectorFuture);
	gameNameText.setString("BlueBlast");
	gameNameText.setCharacterSize(96);
	gameNameText.setFillColor(Color::Blue);
	gameNameText.setStyle(Text::Bold);

	// Setting the origin to the centre
	gameNameText = CentreText(gameNameText);
	gameNameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// Title name text and styling
	playGameText.setFont(arial);
	playGameText.setString("Press <space> to play!");
	playGameText.setCharacterSize(50);
	playGameText.setFillColor(Color::White);

	// Setting the origin to the centre
	playGameText = CentreText(playGameText);
	playGameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);

	gameTimerText.setFont(kenvectorFuture);
	gameTimerText.setString("?.??");
	gameTimerText.setCharacterSize(32);
	gameTimerText.setFillColor(Color::Black);
	gameTimerText = CentreText(gameTimerText);
	gameTimerText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 20.f);

	// Initialise the tiles within the game map
	for (size_t y = 0; y < gameMap.size(); ++y)
		for (size_t x = 0; x < gameMap[y].size(); ++x)
		{
			Tile& t = gameMap[y][x];
			if (t.tileType == Tile::TileType::GRASS)
			{
				t.spr.setTexture(texGrass);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			else if (t.tileType == Tile::TileType::WALL_HORIZONTAL)
			{
				t.spr.setTexture(texWall);
				t.spr.setTextureRect({ 0, 184, 64, 64 });
			}
			else if (t.tileType == Tile::TileType::WALL_VERTICAL)
			{
				t.spr.setTexture(texWall);
				t.spr.setTextureRect({ 0, 64, 64, 64 });
			}
			t.spr.setPosition(offset.x + x * t.spr.getGlobalBounds().width,
				offset.y + y * t.spr.getGlobalBounds().height);
		}

	// Initialise the tiles within the object map
	for (size_t y = 0; y < objMap.size(); ++y)
		for (size_t x = 0; x < objMap[y].size(); ++x)
		{
			Object& t = objMap[y][x];
			if (t.objectType == Object::ObjectType::EMPTY)
			{
				if (isDebugging)
				{
					t.spr.setTexture(tempTexEmpty);
					t.spr.setTextureRect({ 0, 0, 64, 64 });
				}

			}
			else if (t.objectType == Object::ObjectType::DISC)
			{
				t.spr.setTexture(texDisc);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			else if (t.objectType == Object::ObjectType::WIRE)
			{
				t.spr.setTexture(texWire);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			t.spr.setPosition(offset.x + x * t.spr.getGlobalBounds().width,
				offset.y + y * t.spr.getGlobalBounds().height);
		}

	// Initialise the sprite for the player
	player.spr.setTexture(texPlayer);
	player.spr.setTextureRect(IntRect{ 4, 7, 44, 85 });
	player.spr.setScale(1, 0.75f);
	player.spr.setPosition(MapToScrn(1, 1));
	player.damage.setTexture(texElectrocute);
	player.damage.setScale(0, 0);
	player.damage.setPosition(MapToScrn(1, 1));

	for (int i = 0; i < 3; i++)
	{
		sprHeart[i].setTexture(texHeart);
		sprHeart[i].setScale(5, 5);
	}

	sprHeart[0].setPosition(25, offset.y / 2.f);
	sprHeart[1].setPosition(25 * 3, offset.y / 2.f);
	sprHeart[2].setPosition(25 * 5, offset.y / 2.f);
}

void Game::UpdateGame(RenderWindow& window, float timer)
{
	stringstream stream;

	player.stunnedTimer += timer;

	switch (gameState) 
	{
	case GameState::MAIN_MENU:
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			gameState = GameState::INGAME;
		}
		break;
	case GameState::INGAME:
		if (player.health > 0)
		{
			gameTimer += timer;
			stream << fixed << std::setprecision(2) << gameTimer;
			gameTimerText.setString(stream.str());
		}
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

		if (elapsed >= 0.5f && player.health > 0)
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
				// Again check if the move is not touching an object, depedent on the object the player may be harmed or awarded
				if (mapPos.y >= 0 && mapPos.x >= 0 && mapPos.x < (int)(objMap[0].size() - 1) &&
					objMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::DISC && moving == true && player.stunned == false)
				{
					objMap[mapPos.y][mapPos.x].objectType = Object::ObjectType::EMPTY;

					moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.discs += 1;
					UpdateObjectMap(window);
				}
				else if (mapPos.y >= 0 && mapPos.x >= 0 && mapPos.x < (int)(objMap[0].size() - 1) &&
					objMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::WIRE && moving && !player.stunned)
				{
					// The player is electrocuted 
					player.stunned = true;
					moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.damage.setScale(1, 1);

					player.health -= 1;
					UpdateObjectMap(window);
				}
				else if(player.stunned && player.stunnedTimer >= 2.f)
				{
					moving = false;

					player.stunnedTimer = 0.f;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.damage.setScale(0, 0);

					player.stunned = false;
				}		
				else  if (!player.stunned)
				{
					moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

				}
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

		// Drawing sprites/text to the screen
		window.draw(sprBackgroundColor);
		window.draw(sprBackgroundFactory);

		window.draw(playGameText);
		window.draw(gameNameText);
		break;
	case GameState::INGAME:
		window.draw(sprBackground);
		// Draw the 2D maps
		for (size_t y = 0; y < gameMap.size(); ++y)
			for (size_t x = 0; x < gameMap[y].size(); ++x)
			{
				Tile& t = gameMap[y][x];
				window.draw(t.spr);
			}

		UpdateObjectMap(window);
		// Drawing sprites/text to the screen
		window.draw(player.spr);
		window.draw(player.damage);
		break;
	case GameState::ENDSCREEN:
		break;
	}
}

void Game::RenderGameHud(RenderWindow& window)
{

	switch (gameState)
	{
	case GameState::MAIN_MENU:
		break;
	case GameState::INGAME:
		for (int i = 0; i < 3; i++)
		{
			if (player.health >= i + 1)
				window.draw(sprHeart[i]);
		}
		window.draw(gameTimerText);

		if (player.health <= 0)
		{
			RectangleShape shape;
			shape.setScale(500, 500);
			shape.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 2.f);
			shape.setFillColor(Color(0, 0, 0, 255));

			window.draw(shape);
		}
		break;
	case GameState::ENDSCREEN:
		break;
	}
}

void Game::UpdateObjectMap(RenderWindow& window)
{
	// Updating the textures in the object map incase a disc is picked up
	for (size_t y = 0; y < objMap.size(); ++y)
		for (size_t x = 0; x < objMap[y].size(); ++x)
		{
			Object& t = objMap[y][x];
			if (t.objectType == Object::ObjectType::EMPTY)
			{
				if (isDebugging)
				{
					t.spr.setTexture(tempTexEmpty);
					t.spr.setTextureRect({ 0, 0, 64, 64 });
				}

			}
			else if (t.objectType == Object::ObjectType::DISC)
			{
				t.spr.setTexture(texDisc);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			else if (t.objectType == Object::ObjectType::WIRE)
			{
				t.spr.setTexture(texWire);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			t.spr.setPosition(offset.x + x * t.spr.getGlobalBounds().width,
				offset.y + y * t.spr.getGlobalBounds().height);
			window.draw(t.spr);
		}
}