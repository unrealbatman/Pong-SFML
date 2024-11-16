#include "../../Header/Event/EventManager.h"

namespace Event
{
    void EventManager::eventPolling(RenderWindow* game_window)
    {
        sf::Event event;
        while (game_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game_window->close();

            // Check for Escape key to close the game
            if (event.type == sf::Event::KeyPressed && event.key.code == Keyboard::Escape) {
                game_window->close();
            }
        }
    }

    bool EventManager::isKeyPressed(Keyboard::Key key)
    {
        return Keyboard::isKeyPressed(key);
    }

    bool EventManager::isWPressed()
    {
        return isKeyPressed(Keyboard::W);
    }

    bool EventManager::isSPressed()
    {
        return isKeyPressed(Keyboard::S);
    }

    bool EventManager::isUpArrowPressed()
    {
        return isKeyPressed(Keyboard::Up);
    }

    bool EventManager::isDownArrowPressed()
    {
        return isKeyPressed(Keyboard::Down);
    }
}