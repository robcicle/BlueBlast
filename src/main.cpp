#include <assert.h>

#include "SFML/Graphics.hpp"
#include "Game.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(GC::SCREEN_RES.x), static_cast<unsigned int>(GC::SCREEN_RES.y) }), "BlueBlast");

    // Beginning Initialise functions
    Game* game = new Game();

    // Start the game loop 
    sf::Clock timer;
    while (window.isOpen())
    {
        char key = -1;

        // Process events
        bool polled = false;
        while (!polled)
        {
            std::optional<sf::Event> eventOptional = window.pollEvent();
			if (!eventOptional.has_value())
			{
                polled = true;
                break;
			}

            sf::Event event = eventOptional.value();

            // Close window: exit
            if (event.is<sf::Event::Closed>())
                window.close();
            if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
            {
                key = textEntered->unicode;
                if (key == GC::ESCAPE_KEY)
                    window.close();
            }
        }
        // Clear screen
        window.clear();

        float elapsed = timer.getElapsedTime().asSeconds();
        timer.restart();

        // Update and Render the Game
        game->UpdateGame(elapsed, key);
        game->RenderGame(window, elapsed);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
