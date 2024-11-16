// TODO: Fetch for escape key input and if true then close the game window (Stop The Game)
// TODO: Why is this empty? Where are helper functions for fetching player inputs?

#include "EventManager.h"

void EventManager::EventPolling(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        // Check for Escape key to close the game
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
            window.close();
        }
    }
}

bool EventManager::IsKeyPressed(Keyboard::Key key)
{ 
    return Keyboard::isKeyPressed(key); 
}

bool EventManager::IsWPressed()
{
    return Keyboard::isKeyPressed(Keyboard::W);
}

bool EventManager::IsSPressed()
{
    return Keyboard::isKeyPressed(Keyboard::S);
}

bool EventManager::IsUpArrowPressed()
{
    return Keyboard::isKeyPressed(Keyboard::Up);
}

bool EventManager::IsDownArrowPressed()
{
    return Keyboard::isKeyPressed(Keyboard::Down);
}