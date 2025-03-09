#include <assert.h>

#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace sf;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode({ static_cast<unsigned int>(GC::SCREEN_RES.x), static_cast<unsigned int>(GC::SCREEN_RES.y) }), "BlueBlast");

    // Beginning Initialise functions
    Game* game = new Game();

    // Start the game loop 
    Clock timer;
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
            if (event.is<Event::Closed>())
                window.close();
            if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
            {
                auto key = textEntered->unicode;
                if (key == GC::ESCAPE_KEY)
                    window.close();
                if (isdigit(key) || isalpha(key))
                    key = static_cast<char>(key);
                else if (key == GC::BACKSPACE_KEY && !game->metrics.name.empty())
                    game->metrics.name = game->metrics.name.substr(0, game->metrics.name.length() - 1);
            }
        }
        // Clear screen
        window.clear();

        float elapsed = timer.getElapsedTime().asSeconds();
        timer.restart();

        // Updates the game
        game->UpdateGame(window, elapsed, key);

        // Rendering goes here
        game->RenderGame(window, elapsed);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
