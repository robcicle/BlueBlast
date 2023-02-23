#include <assert.h>
#include <vector>

#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace sf;

/*
A box to put Games Constants in.
These are special numbers with important meanings (screen width,
ascii code for the escape key, number of lives a player starts with,
the name of the title screen music track, etc.
*/

int main()
{
	// Create the main window
	RenderWindow window(VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "BlueBlast");

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

		// Update the window
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
	}

	return EXIT_SUCCESS;
}
