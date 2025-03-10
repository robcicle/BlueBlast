#include "Game.h"
#include <sstream>
#include <iomanip>
#include <cassert>
#include <fstream>

// This is the 2D map for the game itself
std::vector<std::vector<Tile>> gameMap
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
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL} }
};

// This is the 2D object map for the items/objects within the game
std::vector<std::vector<Object>> objMap
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
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
};

std::unordered_map<Tile::TileType, sf::Texture*> tileTextures;
std::unordered_map<Object::ObjectType, sf::Texture*> objectTextures;

sf::Vector2f Game::MapToScrn(int x, int y)
{
	sf::Vector2f scrPos(offset.x + x * 64.f, offset.y + y * 64.f);
	return scrPos;
}

sf::Vector2i Game::ScrnToMap(const sf::Vector2f& scrnPos)
{
	sf::Vector2i mapPos((int)(scrnPos.x - offset.x) / 64, (int)(scrnPos.y - offset.y) / 64);
	return mapPos;
}

// Function used to centre text, made to shorten repition
void CentreText(sf::Text* text)
{
	sf::Vector2f textCentre;
	sf::FloatRect textRect;

	// Setting the origin to the centre
	textRect = text->getGlobalBounds();
	textCentre.x = textRect.size.x / 2.0f;
	textCentre.y = textRect.size.y / 2.0f;
	text->setOrigin(textCentre);
}


bool LoadTexture(const std::string& file, sf::Texture& tex)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(true);
		return true;
	}
	assert(false);
	return false;
}

// Initialises the textures, sprites and 2D map
Game::Game()
{
	// Load textures and fonts
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
	assert(kenvectorFuture.openFromFile("data/kenvector_future.ttf"));

	// Initialize background
	sprBackgroundColor = new sf::Sprite(texBackgroundColor);
	sprBackgroundFactory = new sf::Sprite(texBackgroundFactory, { {0, 0}, {272, 104} });
	sprBackgroundColor->scale({ GC::SCREEN_RES.x / 272.f, GC::SCREEN_RES.y / 160.f });
	sprBackgroundFactory->scale({ GC::SCREEN_RES.x / 272.f, GC::SCREEN_RES.y / 160.f });
	sprBackgroundFactory->setPosition(sf::Vector2f(0, 280));

	// Level background
	sprBackground = new sf::Sprite(texWall, { {0, 184}, {64, 64} });
	sprBackground->setScale({ GC::SCREEN_RES.x / 60.f, GC::SCREEN_RES.y / 60.f });

	// Initialize text elements
	InitText(gameNameText, kenvectorFuture, "BlueBlast", 96, sf::Color::Blue, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);
	InitText(playGameText, kenvectorFuture, "Press <space> to Play!", 50, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);
	InitText(gameTimerText, kenvectorFuture, "", 32, sf::Color::Black, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 20.f);
	InitText(discText, kenvectorFuture, "", 52, sf::Color::Black, 85, offset.y / 0.6f);
	InitText(objectiveText, kenvectorFuture, "Objective: Find all the Discs", 16, sf::Color::Black, GC::SCREEN_RES.x - 350.f, offset.y);
	InitText(deadText, kenvectorFuture, "YOU DIED", 96, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);
	InitText(seeScoreText, kenvectorFuture, "Press <space> to see Scores!", 50, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);
	InitText(winText, kenvectorFuture, "YOU WIN", 96, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);
	InitText(proceedText, kenvectorFuture, "Press <space> to proceed", 50, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);
	InitText(restartText, kenvectorFuture, "Press <r> to Restart!", 50, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);
	InitText(enterNameText, kenvectorFuture, "ENTER YOUR NAME:", 84, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);
	InitText(nameText, kenvectorFuture, "_ _ _ _ _ _", 50, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 2.f);
	InitText(scoreTitleText, kenvectorFuture, "SCORES:", 96, sf::Color::White, GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// Initialize score texts
	for (int i = 0; i < 5; i++) {
		InitText(scoreText[i], kenvectorFuture, "", 35, sf::Color::White, GC::SCREEN_RES.x / 2.f, (GC::SCREEN_RES.y / 1.6f) - i * 50);
	}

	// Screen fade effect
	shapeDeath.setSize(sf::Vector2f(GC::SCREEN_RES.x, GC::SCREEN_RES.y));
	shapeDeath.setFillColor({ 0, 0, 0, 0 });

	// Initialize player
	sf::Sprite* playerSprite = new sf::Sprite(texPlayer, { {4, 7}, {44, 85} });
	playerSprite->setScale({ 1, 0.75f });
	sf::Sprite* playerDamageSprite = new sf::Sprite(texElectrocute);
	player = new Player(playerSprite, playerDamageSprite);

	InitLevel();

	// Initialize UI hearts
	for (int i = 0; i < 3; i++) {
		sprHeart[i] = new sf::Sprite(texHeart);
		sprHeart[i]->setScale({ 5, 5 });
	}
	sprHeart[0]->setPosition({ offset.x, offset.y / 2.f });
	sprHeart[1]->setPosition({ offset.x * 3, offset.y / 2.f });
	sprHeart[2]->setPosition({ offset.x * 5, offset.y / 2.f });

	// Disc UI
	sprDiscUi = new sf::Sprite(texDisc);
	sprDiscUi->setPosition({ 30, offset.y / 0.45f });
	sprDiscUi->setScale({ 0.65f, 0.65f });

	// Load metrics
	metrics.Load("data/scores.txt");
}

Game::~Game() {
	delete sprBackgroundColor;
	delete sprBackgroundFactory;
	delete sprBackground;
	delete sprDiscUi;
	delete player;
	for (int i = 0; i < 3; ++i) {
		delete sprHeart[i];
	}
	delete gameNameText;
	delete playGameText;
	delete gameTimerText;
	delete discText;
	delete objectiveText;
	delete seeScoreText;
	delete deadText;
	delete proceedText;
	delete winText;
	delete nameText;
	delete enterNameText;
	delete scoreTitleText;
	for (int i = 0; i < 5; ++i) {
		delete scoreText[i];
	}
	delete restartText;
}

void Game::InitText(sf::Text*& text, sf::Font& font, const std::string& str, unsigned int size, sf::Color color, float x, float y)
{
	text = new sf::Text(font);
	text->setString(str);
	text->setCharacterSize(size);
	text->setFillColor(color);
	text->setStyle(sf::Text::Bold);
	CentreText(text);
	text->setPosition(sf::Vector2f(x, y));
}

void Game::InitLevel()
{
	curObjMap = objMap;

	// Reset player state
	player->Reset();
	player->GetPlayerSprite()->setPosition(MapToScrn(1, 1));
	player->GetDamageSprite()->setScale({ 0, 0 });
	player->GetDamageSprite()->setPosition(MapToScrn(1, 1));

	levelDiscCount = 0;

	// Map tile types to textures
	tileTextures = {
		{Tile::TileType::GRASS, &texGrass},
		{Tile::TileType::WALL_VERTICAL, &texWall},
		{Tile::TileType::WALL_HORIZONTAL, &texWall}
	};

	// Map object types to textures
	objectTextures = {
		{Object::ObjectType::DISC, &texDisc},
		{Object::ObjectType::WIRE, &texWire}
	};

	// Initialize tile sprites
	for (size_t y = 0; y < gameMap.size(); ++y)
	{
		for (size_t x = 0; x < gameMap[y].size(); ++x)
		{
			Tile& t = gameMap[y][x];
			if (tileTextures.count(t.tileType))
			{
				t.spr = new sf::Sprite(*tileTextures[t.tileType]);
				sf::IntRect rect;
				switch (t.tileType)
				{
				case Tile::TileType::WALL_VERTICAL: rect = { {0, 64}, {64, 64} }; break;
				case Tile::TileType::WALL_HORIZONTAL: rect = { {0, 184}, {64, 64} }; break;
				case Tile::TileType::GRASS: rect = { {0, 0}, {64, 64} }; break;
				}
				t.spr->setTextureRect(rect);
				t.spr->setPosition(sf::Vector2f(offset.x + x * 64, offset.y + y * 64));
			}
		}
	}

	// Initialize object sprites
	for (size_t y = 0; y < curObjMap.size(); ++y)
	{
		for (size_t x = 0; x < curObjMap[y].size(); ++x)
		{
			Object& o = curObjMap[y][x];
			if (objectTextures.count(o.objectType))
			{
				o.spr = new sf::Sprite(*objectTextures[o.objectType], { {0, 0}, { 64, 64 } });
				o.spr->setPosition(sf::Vector2f(offset.x + x * 64, offset.y + y * 64));
			}
			else if (o.objectType == Object::ObjectType::EMPTY && isDebugging)
			{
				o.spr = new sf::Sprite(tempTexEmpty, { {0, 0}, {64, 64} });
				o.spr->setPosition(sf::Vector2f(offset.x + x * 64, offset.y + y * 64));
			}
			if (o.objectType == Object::ObjectType::DISC)
			{
				levelDiscCount++;
			}
		}
	}

	// Reset timers
	gameTimer = 0.0f;
	timer = 0.0f;
	tallyTimer = 0.0f;

	// Update disc counter text
	discText->setString(std::to_string(player->GetDiscs()) + "/" + std::to_string(levelDiscCount));

	// Reset death fade overlay
	shapeDeath.setFillColor({ 0, 0, 0, 0 });
}

void Game::UpdateGame(float elapsed, char key)
{
	std::stringstream stream;

	switch (gameState)
	{
	case GameState::MAIN_MENU:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			gameState = GameState::INGAME;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			gameState = GameState::DEAD_SCREEN;
		}
		break;

	case GameState::INGAME:
		if (player->GetHealth() > 0 && player->GetDiscs() < levelDiscCount)
		{
			gameTimer += elapsed;
			stream << std::fixed << std::setprecision(0) << gameTimer;
			gameTimerText->setString(stream.str());
			CentreText(gameTimerText);
			tallyTimer = gameTimer;
		}

		player->UpdateStunned(elapsed);
		timer += elapsed;

		player->SetMovement();

		if (timer >= 0.5f && player->GetHealth() > 0 && player->GetDiscs() < levelDiscCount)
		{
			timer = 0.f;
			sf::Vector2i mapPos = ScrnToMap(player->GetPlayerSprite()->getPosition());
			sf::Vector2i newPos = player->Move(gameMap, curObjMap, sf::Vector2f(0,0), mapPos);
			sf::Vector2f screenPos = MapToScrn(newPos.x, newPos.y);
			player->GetPlayerSprite()->setPosition(screenPos);
			player->GetDamageSprite()->setPosition(screenPos);
			discText->setString(std::to_string(player->GetDiscs()) + "/" + std::to_string(levelDiscCount));
		}
		else if (timer >= 5.f)
		{
			if (player->GetHealth() <= 0)
			{
				metrics.time = 0.f;
				gameState = GameState::DEAD_SCREEN;
			}
			else if (player->GetDiscs() >= levelDiscCount)
			{
				metrics.time = tallyTimer;
				gameState = GameState::WIN_SCREEN;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
			InitLevel();
		break;

	case GameState::DEAD_SCREEN:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			gameState = GameState::SCORE_SCREEN;
		break;

	case GameState::WIN_SCREEN:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			if (metrics.IsScoreInTopFive() && metrics.name.empty())
				gameState = GameState::ENTER_NAME;
			else
			{
				metrics.SortAndUpdatePlayerData();
				gameState = GameState::SCORE_SCREEN;
			}
		}
		break;

	case GameState::ENTER_NAME:
		if (key == GC::BACKSPACE_KEY && metrics.name.length() > 0)
		{
			metrics.name.pop_back();
		}
		else if (key != -1 && metrics.name.length() < 12)
		{
			metrics.name += key;
		}
		if (metrics.name.size() > 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			gameState = GameState::SCORE_SCREEN;
			metrics.SortAndUpdatePlayerData();
			metrics.Save();
		}
		nameText->setString(metrics.name);
		CentreText(nameText);
		break;

	case GameState::SCORE_SCREEN:
		metrics.Load("data/scores.txt");

		for (size_t i = 0; i < metrics.playerData.size(); i++)
		{
			scoreText[i]->setString(
				metrics.playerData[i].name.empty() ? "Unable to load PlayerData" :
				metrics.playerData[i].name + " - " + std::to_string(metrics.playerData[i].time) + "s");
			CentreText(scoreText[i]);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			InitLevel();
			gameState = GameState::MAIN_MENU;
		}
		break;
	}
}

void Game::RenderGame(sf::RenderWindow& window, float elapsed)
{
	switch (gameState)
	{
	case GameState::MAIN_MENU:
		// Draw background and menu text
		window.draw(*sprBackgroundColor);
		window.draw(*sprBackgroundFactory);
		window.draw(*playGameText);
		window.draw(*gameNameText);
		break;

	case GameState::INGAME:
		// Draw the game background
		window.draw(*sprBackground);

		// Draw the tile map
		for (const auto& row : gameMap)
		{
			for (const Tile& tile : row)
			{
				if (tile.spr)
					window.draw(*tile.spr);
			}
		}

		// Draw objects dynamically
		// Updates if any objects are picked up
		UpdateObjectMap(window);

		// Draw player and damage sprite
		window.draw(*player->GetPlayerSprite());
		window.draw(*player->GetDamageSprite());

		// Render game HUD (score, health, timer)
		RenderGameHud(window, elapsed);
		break;

	case GameState::DEAD_SCREEN:
		// Draw death screen text
		window.draw(*seeScoreText);
		window.draw(*deadText);
		break;

	case GameState::WIN_SCREEN:
		// Draw win screen text
		window.draw(*proceedText);
		window.draw(*winText);
		break;

	case GameState::ENTER_NAME:
		// Draw text entry screen
		window.draw(*nameText);
		window.draw(*enterNameText);
		break;

	case GameState::SCORE_SCREEN:
		// Draw scoreboard and restart prompt
		window.draw(*restartText);
		window.draw(*scoreTitleText);

		// Draw the top 5 player scores
		for (int i = 0; i < 5; ++i)
		{
			if (scoreText[i])
			{
				window.draw(*scoreText[i]);
			}
		}
		break;
	}
}

void Game::RenderGameHud(sf::RenderWindow& window, float elapsed)
{
	for (int i = 0; i < 3; i++)
	{
		if (player->GetHealth() >= i + 1)
			window.draw(*sprHeart[i]);
	}

	window.draw(*gameTimerText);
	window.draw(*sprDiscUi);
	window.draw(*discText);
	window.draw(*objectiveText);

	endTimer += elapsed;
	if (player->GetHealth() <= 0 || player->GetDiscs() >= levelDiscCount)
	{
		if (endTimer >= 1.f)
		{
			endTimer = 0.f;

			if (shapeDeath.getFillColor().a < 255)
				shapeDeath.setFillColor(sf::Color(0, 0, 0, shapeDeath.getFillColor().a + 51));
		}

		window.draw(shapeDeath);
	}
}

void Game::UpdateObjectMap(sf::RenderWindow& window) {
	for (size_t y = 0; y < curObjMap.size(); ++y) {
		for (size_t x = 0; x < curObjMap[y].size(); ++x) {
			Object& o = curObjMap[y][x];

			if (objectTextures.find(o.objectType) != objectTextures.end()) {
				delete o.spr;
				o.spr = new sf::Sprite(*objectTextures[o.objectType], sf::IntRect(sf::Vector2(0, 0), sf::Vector2(64, 64)));
				o.spr->setPosition(sf::Vector2f(offset.x + x * o.spr->getGlobalBounds().size.x,
					offset.y + y * o.spr->getGlobalBounds().size.y));
			}
			else if (o.objectType == Object::ObjectType::EMPTY && isDebugging) {
				delete o.spr;
				o.spr = new sf::Sprite(tempTexEmpty, sf::IntRect(sf::Vector2(0, 0), sf::Vector2(64, 64)));
				o.spr->setPosition(sf::Vector2f(offset.x + x * o.spr->getGlobalBounds().size.x,
					offset.y + y * o.spr->getGlobalBounds().size.y));
			}

			if (o.isVisible) {
				if (o.objectType == Object::ObjectType::EMPTY) {
					if (isDebugging) {
						window.draw(*o.spr);
					}
				}
				else {
					window.draw(*o.spr);
				}
			}
		}
	}
}