#pragma once

#include "SFML/Graphics.hpp"
#include "Utils.h"

// Used to hold numbers with important meanings e.g. screen resolution
namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 1200,800 };
	const char ESCAPE_KEY{ 27 };
	const char BACKSPACE_KEY{ 8 };
}

/*
Data about the game for high scores and possibly
tracking stats about players
*/
struct Metrics {
	const std::string VERSION = "1.0";	// Current game version
	float time;				// Session time
	std::string name;		// Current players name

	// Hold data together so it can be saved as a container
	struct PlayerData {
		std::string name;
		float time = 0;
	};
	std::vector<PlayerData> playerData;		// Last five players data
	std::string filePath;		// Data storage location

	// Use this whenever a new game is played to reset data such as name and time
	void Restart();
	// Is the new score in the top five
	bool IsScoreInTopFive();
	/*
	Figure out if current score qualifies for the top five,
	if it does then add it to the data and then resort the playerData vector to corrospond to it
	the lowest first entry in the vector is the highest (playerData[0].time)
	*/
	void SortAndUpdatePlayerData();
	/*Load in the player data
	path - path of the database/file
	_useDB - wether or not the data is a .db or .txt
	*/
	bool Load(const std::string& path) {
		return FileLoad(path);
	}
	/*Save all of the player data
	path - path is optional as it should have been loaded before
	*/
	bool Save(const std::string& path = "") {
		return FileSave(path);
	}

	// Stream the data to and from the .txt file
	bool FileSave(const std::string& path = "");
	bool FileLoad(const std::string& path);
};

/*
Used to hold data about the Tile which is then used an
vector array to make up the 2D map of the game
*/
struct Tile 
{
	enum class TileType { GRASS, WALL_VERTICAL, WALL_HORIZONTAL } tileType = Tile::TileType::GRASS; // Each tile type holds a sprite making it a key asset when it comes to rendering out the map itself
	sf::Sprite* spr;
};

/*
Used to hold data about the Object which is then used an
vector array to make up the 2D object map of the game
*/
struct Object
{
	enum class ObjectType { EMPTY, DISC, WIRE } objectType = Object::ObjectType::EMPTY; // Each tile type holds a sprite making it a key asset when it comes to rendering out the map itself
	bool isVisible = true;
	sf::Sprite* spr;
};

class Game
{
public:
	// Initialises the textures, sprites, 2D map and object map.
	Game();

	/* Make calculations to be able to move the player, check if they pickup an item. overall, updates the logic of the game
	window - need it to be able to draw things to the screen, get the resoultion of the window, etc.
	elapsed - this is the frame time which is used for physics code, e.g. player movement
	*/
	void UpdateGame(sf::RenderWindow& window, float elapsed, char key);
	/* Draws out anything that needs to be rendered to the screen
	window - need it to be able to draw things to the screen, get the resoultion of the window, etc.
	elapsed - incase anything is rotating/being animated
	*/
	void RenderGame(sf::RenderWindow& window, float elapsed);
public:
	Metrics metrics; // A container to hold the ability to record player name and time for their final score
private:
	// Textures that will be needed and should only be loaded once.
	sf::Texture texGrass;
	sf::Texture texPlayer;
	sf::Texture texElectrocute;
	sf::Texture texWall;
	sf::Texture texHeart;
	sf::Texture texDisc;
	sf::Texture texWire;
	sf::Texture tempTexEmpty;
	sf::Texture texBackgroundColor;
	sf::Texture texBackgroundFactory;

	std::vector<std::vector<Object>> curObjMap; // Is used to set the current levels obj map, helps when restarting levels

	// Game state so that we can differntiate between what needs to be run during which state
	enum class GameState { MAIN_MENU, INGAME, DEAD_SCREEN, WIN_SCREEN, ENTER_NAME, SCORE_SCREEN } gameState = GameState::MAIN_MENU;

	sf::Vector2f offset{ 25, 25 }; // Offset of the 2D map, is used to correctly align other sprites

	bool isDebugging = false; // When is true reveals a sprite for the EMPTY components in the object map, helpful for debugging or changing layout

	float timer = 0.0f; // Timer is used to limit player movement to every half a second
	float gameTimer = 0.0f; // This is used to keep track of the amount of time it takes a player to complete the level, will become players final score
	float tallyTimer = 0.0f; // Will take the gameTimer once game has ended to add towards score
	float endTimer = 0.0f; // Used to slowly fade the screen black upon death
	int levelDiscCount = 0; // Used to automatically determine how many discs are in the level to add towards final score


	// Sprites that are needed
	sf::Sprite* sprBackgroundColor;
	sf::Sprite* sprBackgroundFactory;
	sf::Sprite* sprHeart[3];
	sf::Sprite* sprBackground;
	sf::Sprite* sprDiscUi;

	// Fonts that are needed
	sf::Font arial;
	sf::Font kenvectorFuture;

	// Text that is needed
	sf::Text* gameNameText; // Title screen text to display game name
	sf::Text* playGameText; // Title screen text to display helpful text to begin playing

	sf::Text* gameTimerText; // Ingame text used to display players current time within the level
	sf::Text* discText; // Ingame text used to display the players current disc count
	sf::Text* objectiveText; // Ingame text used to display the current objective to the player

	sf::Text* seeScoreText; // Endscreen text used to display how the player is able to see the scores
	sf::Text* deadText; // Endscreen text used to display the player has died

	sf::Text* proceedText; // Win screen text used to display how the player is able to proceed
	sf::Text* winText; // Win screen text used to display the player has completed the game

	sf::Text* nameText; // Text used to display the name the player is currently typing
	sf::Text* enterNameText; // Enter name text used to display the player should enter their name

	sf::Text* scoreTitleText; // Score title text
	sf::Text* scoreText[5]; // Score text used to display the different player scores
	sf::Text* restartText; // Score Screen text used to display how to restart to the player

	sf::RectangleShape shapeDeath; // Used to fade the screen to black upon death

	
	// Initialises/reinitialises anything to do with the game and the beginning logic of it, 2D
	void InitLevel();
	//Renders out any of the HUD/UI, is it's own function and called after update to be layed on top of the game itself
	void RenderGameHud(sf::RenderWindow& window, float elapsed);
	// Used whenever a player picks up an item and the object map needs re-rendering to graphically remove anything taken from the map
	void UpdateObjectMap(sf::RenderWindow& window);

	sf::Vector2f MapToScrn(int x, int y); // Used to be able to find the players position from its position on the map (from map position to screen position)
	sf::Vector2i ScrnToMap(const sf::Vector2f& scrnPos); // Used to be able to map the player/items correctly on the map (from screen position to map position)
};

bool LoadTexture(const std::string& file, sf::Texture& tex);