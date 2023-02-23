#include <assert.h>

#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace sf;

int main()
{
	// Create the main window
	RenderWindow window(VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "BlueBlast");

	RenderTarget* target();

	// Beginning Initialise functions
	Game game;
	game.Init();

	// Start the game loop 
	Clock timer;
	while (window.isOpen())
	{
		// Process events
		Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == Event::Closed) 
				window.close();
			if (event.type == Event::TextEntered)
			{
				if (event.text.unicode == GC::ESCAPE_KEY)
					window.close();
			}
		} 
		// Clear screen
		window.clear();

		float elapsed = timer.getElapsedTime().asSeconds();
		timer.restart();

		// Updates the game
		game.UpdateGame(elapsed);

		// Rendering goes here
		game.RenderGame(window);
		game.RenderGameHud(window);

		// Update the window
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
	}

	return EXIT_SUCCESS;
}