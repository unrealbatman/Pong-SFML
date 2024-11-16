// TODO: Fetch for escape key input and if true then close the game window (Stop The Game)
// TODO: Why is this empty? Where are helper functions for fetching player inputs?

#include "EventManager.h"

void EventManager::eventPolling(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();

        // Check for Escape key to close the game
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
            window.close();
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