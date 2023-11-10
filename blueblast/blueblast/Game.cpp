#include <assert.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>
#include <fstream>

#include "Game.h"

using namespace sf;
using namespace std;

void Metrics::SortAndUpdatePlayerData() {
	PlayerData d{ name,time };
	playerData.push_back(d);
}


bool Metrics::DBLoad(const std::string& path) 
{

	return false;
}

bool Metrics::FileSave(const std::string& path) 
{

	if (!path.empty())
		filePath = path;
	ofstream fs;
	fs.open(filePath);
	if (fs.is_open() && fs.good())
	{
		fs << VERSION;
		for (size_t i = 0; i < playerData.size(); ++i)
		{
			fs << ' ' << playerData[i].name << ' ' << playerData[i].time;
		}
		assert(!fs.fail());
		fs.close();
	}
	else
	{
		assert(false);
		return false;
	}
	return true;
}

bool Metrics::DBSave(const std::string& path) 
{

	return false;
}

bool Metrics::FileLoad(const std::string& path) 
{

	assert(!path.empty());
	filePath = path;
	ifstream fs;
	fs.open(filePath, ios::binary);
	if (fs.is_open() && fs.good())
	{
		string version;
		fs >> version;
		if (version == VERSION)
		{
			playerData.clear();
			while (!fs.eof()) {
				PlayerData d;
				fs >> d.name;
				assert(!d.name.empty());
				fs >> d.time;
				assert(d.time >= 0);
				playerData.push_back(d);
			}
		}
		assert(!fs.fail());
		fs.close();
	}
	return false;
}

bool Metrics::IsScoreInTopFive() 
{
	if (playerData.size() < 5)
		return true;
	return playerData.back().time > time;
}

void Metrics::Restart() 
{
	time = 0;
}

// This is the 2D map for the game itself
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
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::GRASS},{Tile::TileType::WALL_VERTICAL} },
	{ {Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL},{Tile::TileType::WALL_HORIZONTAL} }
};

// This is the 2D object map for the items/objects within the game
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
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY} },
	{ {Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::WIRE},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY},{Object::ObjectType::DISC},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY},{Object::ObjectType::EMPTY} },
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

// Function used to centre text, made to shorten repition
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

// Player struct to hold information and create our player
struct Player {
	Sprite spr;
	Sprite damage;
	float stunnedTimer = 0.0f;
	bool moving = false;
	bool stunned = false;
	int discs = 0;
	int health = 3;
	enum class Heading { UP, DOWN, LEFT, RIGHT } heading = Heading::RIGHT;
} player;

// Initialises the textures, sprites and 2D map
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
	gameNameText = CentreText(gameNameText);
	gameNameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// Play game text and styling
	playGameText.setFont(arial);
	playGameText.setString("Press <space> to Play!");
	playGameText.setCharacterSize(50);
	playGameText.setFillColor(Color::White);
	playGameText = CentreText(playGameText);
	playGameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);

	// Game timer text and styling
	gameTimerText.setFont(kenvectorFuture);
	gameTimerText.setCharacterSize(32);
	gameTimerText.setFillColor(Color::Black);
	gameTimerText = CentreText(gameTimerText);
	gameTimerText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 20.f);

	// Disc timer text and styling
	discText.setFont(kenvectorFuture);
	discText.setCharacterSize(52);
	discText.setFillColor(Color::Black);
	discText.setPosition(85, offset.y / 0.6f);

	// Objective text and styling
	objectiveText.setFont(kenvectorFuture);
	objectiveText.setString("Objective: Find all the Discs");
	objectiveText.setCharacterSize(16);
	objectiveText.setFillColor(Color::Black);
	objectiveText.setPosition(GC::SCREEN_RES.x - 350.f, offset.y);

	// End game text and styling
	deadText.setFont(kenvectorFuture);
	deadText.setString("YOU DIED");
	deadText.setCharacterSize(96);
	deadText.setFillColor(Color::White);
	deadText.setStyle(Text::Bold);
	deadText = CentreText(deadText);
	deadText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// See score text and styling
	seeScoreText.setFont(arial);
	seeScoreText.setString("Press <space> to see Scores!");
	seeScoreText.setCharacterSize(50);
	seeScoreText.setFillColor(Color::White);
	seeScoreText.setStyle(Text::Bold);
	seeScoreText = CentreText(seeScoreText);
	seeScoreText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);
	
	// Win game text and styling
	winText.setFont(kenvectorFuture);
	winText.setString("YOU WIN");
	winText.setCharacterSize(96);
	winText.setFillColor(Color::White);
	winText.setStyle(Text::Bold);
	winText = CentreText(winText);
	winText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// Proceed to the next state text and styling
	proceedText.setFont(arial);
	proceedText.setString("Press <space> to proceed");
	proceedText.setCharacterSize(50);
	proceedText.setFillColor(Color::White);
	proceedText.setStyle(Text::Bold);
	proceedText = CentreText(proceedText);
	proceedText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);

	// Restart game text and styling
	restartText.setFont(arial);
	restartText.setString("Press <r> to Restart!");
	restartText.setCharacterSize(50);
	restartText.setFillColor(Color::White);
	restartText.setStyle(Text::Bold);
	restartText = CentreText(restartText);
	restartText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 1.1f);

	// Enter name text and styling
	enterNameText.setFont(kenvectorFuture);
	enterNameText.setString("ENTER YOUR NAME:");
	enterNameText.setCharacterSize(84);
	enterNameText.setFillColor(Color::White);
	enterNameText.setStyle(Text::Bold);
	enterNameText = CentreText(enterNameText);
	enterNameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// Name typing text and styling
	nameText.setFont(arial);
	nameText.setString("_ _ _ _ _ _");
	nameText.setCharacterSize(50);
	nameText.setFillColor(Color::White);
	nameText.setStyle(Text::Bold);
	nameText = CentreText(nameText);
	nameText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 2.f);

	// Score Title text and styling
	scoreTitleText.setFont(arial);
	scoreTitleText.setString("SCORES:");
	scoreTitleText.setCharacterSize(96);
	scoreTitleText.setFillColor(Color::White);
	scoreTitleText.setStyle(Text::Bold);
	scoreTitleText = CentreText(scoreTitleText);
	scoreTitleText.setPosition(GC::SCREEN_RES.x / 2.f, GC::SCREEN_RES.y / 5.f);

	// For loop to loop through the array of score text and set the styling for each one
	for (int i = 0; i < 5; i++)
	{
		scoreText[i].setFont(arial);
		scoreText[i].setString("name - time.time");
		scoreText[i].setCharacterSize(35);
		scoreText[i].setFillColor(Color::White);
		scoreText[i].setStyle(Text::Bold);

		Vector2f scoreTextCentre;
		FloatRect scoreTextRect;

		scoreTextRect = scoreText[i].getGlobalBounds();
		scoreTextCentre.x = scoreTextRect.width / 2.0f;
		scoreTextCentre.y = scoreTextRect.height;

		scoreText[i].setOrigin(scoreTextCentre);
		scoreText[i].setPosition(GC::SCREEN_RES.x / 2.f, (GC::SCREEN_RES.y / 1.6f) - i * 50);
	}

	// Shape used to slowly fade the screen upon the end of the level
	shapeDeath.setSize(Vector2f((float)GC::SCREEN_RES.x, (float)GC::SCREEN_RES.y));
	shapeDeath.setPosition(0, 0);
	shapeDeath.setFillColor(sf::Color(0, 0, 0, 0));

	InitLevel();

	// Initialise the sprite for the player
	player.spr.setTexture(texPlayer);
	player.spr.setTextureRect(IntRect{ 4, 7, 44, 85 });
	player.spr.setScale(1, 0.75f);
	player.damage.setTexture(texElectrocute);

	// Initialising and positioning sprites for UI
	for (int i = 0; i < 3; i++)
	{
		sprHeart[i].setTexture(texHeart);
		sprHeart[i].setScale(5, 5);
	}

	sprHeart[0].setPosition(offset.x, offset.y / 2.f);
	sprHeart[1].setPosition(offset.x * 3, offset.y / 2.f);
	sprHeart[2].setPosition(offset.x * 5, offset.y / 2.f);

	sprDiscUi.setTexture(texDisc);
	sprDiscUi.setPosition(30, offset.y / 0.45f);
	sprDiscUi.setScale(0.65f, 0.65f);

	metrics.Load("data/scores.txt", false);
}

// Initialises/reinitialises anything to do with the game and the beginning logic of it, 2D Object map, etc.
void Game::InitLevel()
{
	curObjMap = objMap;

	player.spr.setPosition(MapToScrn(1, 1));
	player.damage.setScale(0, 0);
	player.damage.setPosition(MapToScrn(1, 1));

	player.stunnedTimer = 0.0f;
	player.moving = false;
	player.stunned = false;
	player.discs = 0;
	player.health = 3;
	player.heading = Player::Heading::RIGHT;

	levelDiscCount = 0;

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
	for (size_t y = 0; y < curObjMap.size(); ++y)
		for (size_t x = 0; x < curObjMap[y].size(); ++x)
		{
			Object& t = curObjMap[y][x];
			if (t.objectType == Object::ObjectType::EMPTY)
			{
				if (isDebugging)
					t.isVisible = true;
				else
					t.isVisible = false;

				t.spr.setTexture(tempTexEmpty);
				t.spr.setTextureRect({ 0, 0, 64, 64 });

			}
			else if (t.objectType == Object::ObjectType::DISC)
			{
				t.spr.setTexture(texDisc);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
				levelDiscCount += 1;
			}
			else if (t.objectType == Object::ObjectType::WIRE)
			{
				t.spr.setTexture(texWire);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
			}
			t.spr.setPosition(offset.x + x * t.spr.getGlobalBounds().width,
				offset.y + y * t.spr.getGlobalBounds().height);
		}

	gameTimer = 0.0f;
	timer = 0.0f;
	tallyTimer = 0.0f;

	discText.setString(to_string(player.discs) + "/" + to_string(levelDiscCount));

	shapeDeath.setFillColor(Color(0, 0, 0, 0));
}

// Updates the logic of the game
void Game::UpdateGame(RenderWindow& window, float elapsed, char key)
{
	stringstream stream;

	switch (gameState)
	{
	case GameState::MAIN_MENU:
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			gameState = GameState::INGAME;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			gameState = GameState::DEAD_SCREEN;
		}
		break;
	case GameState::INGAME:
		// Timer keeps going until player is either dead or wins
		if (player.health > 0 && player.discs < levelDiscCount)
		{
			gameTimer += elapsed;
			stream << fixed << std::setprecision(0) << gameTimer;
			gameTimerText.setString(stream.str());
			gameTimerText = CentreText(gameTimerText);
			tallyTimer = gameTimer;
		}

		player.stunnedTimer += elapsed;
		timer += elapsed;

		// Get user input to change direction
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			player.heading = Player::Heading::UP;
			player.moving = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
		{
			player.heading = Player::Heading::DOWN;
			player.moving = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			player.heading = Player::Heading::LEFT;
			player.moving = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			player.heading = Player::Heading::RIGHT;
			player.moving = true;
		}

		if (timer >= 0.5f && player.health > 0 && player.discs < levelDiscCount)
		{
			timer = 0.f;
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
				gameMap[mapPos.y][mapPos.x].tileType == Tile::TileType::GRASS && player.moving == true)
			{
				// Again check if the move is not touching an object, depedent on the object the player may be harmed or awarded
				if (mapPos.y >= 0 && mapPos.x >= 0 && mapPos.x < (int)(curObjMap[0].size() - 1) &&
					curObjMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::DISC && player.moving == true && player.stunned == false)
				{
					curObjMap[mapPos.y][mapPos.x].objectType = Object::ObjectType::EMPTY;

					player.moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.discs += 1;
					discText.setString(to_string(player.discs) + "/" + to_string(levelDiscCount));
				}
				else if (mapPos.y >= 0 && mapPos.x >= 0 && mapPos.x < (int)(curObjMap[0].size() - 1) &&
					curObjMap[mapPos.y][mapPos.x].objectType == Object::ObjectType::WIRE && player.moving && !player.stunned)
				{
					// The player is electrocuted 
					player.stunned = true;
					player.moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.damage.setScale(1, 1);

					player.health -= 1;
				}
				else if (player.stunned && player.stunnedTimer >= 2.f)
				{
					player.moving = false;

					player.stunnedTimer = 0.f;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

					player.damage.setScale(0, 0);

					player.stunned = false;
				}
				else  if (!player.stunned)
				{
					player.moving = false;

					player.spr.setPosition(MapToScrn(mapPos.x, mapPos.y));
					player.damage.setPosition(MapToScrn(mapPos.x, mapPos.y));

				}
			}
		}
		else if (timer >= 5.f)
		{
			if (player.health <= 0)
			{
				metrics.time = 0.f;
				gameState = GameState::DEAD_SCREEN;
			}
			else if (player.discs >= levelDiscCount)
			{
				metrics.time = tallyTimer;
				gameState = GameState::WIN_SCREEN;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			InitLevel();
		}
		break;
	case GameState::DEAD_SCREEN:
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			gameState = GameState::SCORE_SCREEN;
		}
		break;
	case GameState::WIN_SCREEN:
		if (Keyboard::isKeyPressed(Keyboard::Space))
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
		if (key != -1 && metrics.name.length() <= 12)
			metrics.name += key;
		if (metrics.name.size() > 1 && Keyboard::isKeyPressed(Keyboard::Return)) {
			gameState = GameState::SCORE_SCREEN;
			metrics.SortAndUpdatePlayerData();
			metrics.Save();
		}
		nameText.setString(metrics.name);
		nameText = CentreText(nameText);
		break;
	case GameState::SCORE_SCREEN:
		metrics.Load("data/scores.txt", false);
		InitLevel();

		for (int i = 0; i < 5; i++)
		{
			if (metrics.playerData[i].name.empty())
				scoreText[i].setString("#### - ##.#####");
			else 
				scoreText[i].setString(metrics.playerData[i].name + " - " + to_string(metrics.playerData[i].time) + "s");
		}

		if (Keyboard::isKeyPressed(Keyboard::R))
			gameState = GameState::MAIN_MENU;
		break;
	}
}

// Renders out anything that needs to be rendered
void Game::RenderGame(RenderWindow& window, float elapsed)
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
		// Drawing the background for the map
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

		RenderGameHud(window, elapsed);
		break;
	case GameState::DEAD_SCREEN:
		window.draw(seeScoreText);
		window.draw(deadText);
		break;
	case GameState::WIN_SCREEN:
		window.draw(proceedText);
		window.draw(winText);
		break;
	case GameState::ENTER_NAME:
		window.draw(nameText);
		window.draw(enterNameText);
		break;
	case GameState::SCORE_SCREEN:
		window.draw(restartText);
		for (int i = 0; i < 5; i++)
		{
			window.draw(scoreText[i]);
		}
		window.draw(scoreTitleText);
		break;
	}
}

// Renders out any of the HUD/UI, is it's own function and called after update to be layed on top of the game itself
void Game::RenderGameHud(RenderWindow& window, float elapsed)
{
	for (int i = 0; i < 3; i++)
	{
		if (player.health >= i + 1)
			window.draw(sprHeart[i]);
	}

	window.draw(gameTimerText);
	window.draw(sprDiscUi);
	window.draw(discText);
	window.draw(objectiveText);

	endTimer += elapsed;
	if (player.health <= 0 || player.discs >= levelDiscCount)
	{
		if (endTimer >= 1.f)
		{
			endTimer = 0.f;

			if (shapeDeath.getFillColor().a < 255)
				shapeDeath.setFillColor(Color(0, 0, 0, shapeDeath.getFillColor().a + 51));
		}

		window.draw(shapeDeath);
	}
}

// Is to be called whenever a player picks up an item and the object map needs re-rendering to remove anything taken
void Game::UpdateObjectMap(RenderWindow& window)
{
	// Updating the textures in the object map incase a disc is picked up
	for (size_t y = 0; y < curObjMap.size(); ++y)
		for (size_t x = 0; x < curObjMap[y].size(); ++x)
		{
			Object& t = curObjMap[y][x];
			if (t.objectType == Object::ObjectType::EMPTY)
			{
				if (isDebugging)
					t.isVisible = true;
				else
					t.isVisible = false;

				t.spr.setTexture(tempTexEmpty);
				t.spr.setTextureRect({ 0, 0, 64, 64 });
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
			
			if (t.isVisible)
				window.draw(t.spr);
		}
}