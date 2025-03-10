#pragma once

#include "SFML/Graphics.hpp"
#include "Metrics.h"
#include "Tile.h"
#include "Object.h"
#include "Player.h"
#include "Utils.h"
#include <vector>

namespace GC {
    const Dim2Di SCREEN_RES{ 1200, 800 };
    const char ESCAPE_KEY{ 27 };
    const char BACKSPACE_KEY{ 8 };
}

class Game {
public:
    Game();
	~Game();
    void UpdateGame(float elapsed, char key);
    void RenderGame(sf::RenderWindow& window, float elapsed);

public:
    Metrics metrics;

private:
    void InitText(sf::Text*& text, sf::Font& font, const std::string& str, unsigned int size, sf::Color color, float x, float y);
    void InitLevel();
    void RenderGameHud(sf::RenderWindow& window, float elapsed);
    void UpdateObjectMap(sf::RenderWindow& window);

    sf::Vector2f MapToScrn(int x, int y);
    sf::Vector2i ScrnToMap(const sf::Vector2f& scrnPos);
private:
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

    std::vector<std::vector<Object>> curObjMap;

    enum class GameState { MAIN_MENU, INGAME, DEAD_SCREEN, WIN_SCREEN, ENTER_NAME, SCORE_SCREEN } gameState = GameState::MAIN_MENU;

    Player* player;

    sf::Vector2f offset{ 25, 25 };

    bool isDebugging = false;

    float timer = 0.0f;
    float gameTimer = 0.0f;
    float tallyTimer = 0.0f;
    float endTimer = 0.0f;
    int levelDiscCount = 0;

    sf::Sprite* sprBackgroundColor;
    sf::Sprite* sprBackgroundFactory;
    sf::Sprite* sprHeart[3];
    sf::Sprite* sprBackground;
    sf::Sprite* sprDiscUi;

    sf::Font arial;
    sf::Font kenvectorFuture;

    sf::Text* gameNameText;
    sf::Text* playGameText;
    sf::Text* gameTimerText;
    sf::Text* discText;
    sf::Text* objectiveText;
    sf::Text* seeScoreText;
    sf::Text* deadText;
    sf::Text* proceedText;
    sf::Text* winText;
    sf::Text* nameText;
    sf::Text* enterNameText;
    sf::Text* scoreTitleText;
    sf::Text* scoreText[5];
    sf::Text* restartText;

    sf::RectangleShape shapeDeath;
};

bool LoadTexture(const std::string& file, sf::Texture& tex);