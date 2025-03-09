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
		char key = -1;

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
				if (isdigit(event.text.unicode) || isalpha(event.text.unicode))
					key = static_cast<char>(event.text.unicode);
				else if (event.text.unicode == GC::BACKSPACE_KEY && !game.metrics.name.empty())
					game.metrics.name = game.metrics.name.substr(0, game.metrics.name.length() - 1);
			}
		} 
		// Clear screen
		window.clear();

		float elapsed = timer.getElapsedTime().asSeconds();
		timer.restart();

		// Updates the game
		game.UpdateGame(window, elapsed, key);

		// Rendering goes here
		game.RenderGame(window, elapsed);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}