#include "../../Header/Event/EventManager.h"

namespace Event {

    void EventManager::pollEvents(sf::RenderWindow* game_window) {
        sf::Event event;

        // Poll all events in the queue
        while (game_window->pollEvent(event)) {
            // Handle window close event
            if (event.type == sf::Event::Closed) {
                game_window->close();
            }

            // Use helper functions for handling specific events
            if (isKeyPressed(sf::Keyboard::Escape)) {
                game_window->close(); // Quit the game on "Escape"
            }

        }
    }

    bool EventManager::isKeyPressed(sf::Keyboard::Key key) {
        // Detect if a specific key is pressed
        return sf::Keyboard::isKeyPressed(key);
    }

}
