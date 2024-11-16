// TODO: Fetch for escape key input and if true then close the game window (Stop The Game)
// TODO: Why is this empty? Where are helper functions for fetching player inputs?

#include "EventManager.h"

void EventManager::EventPolling(RenderWindow& window)
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

bool EventManager::IsKeyPressed(Keyboard::Key key)
{ 
    return Keyboard::isKeyPressed(key); 
}

bool EventManager::IsWPressed()
{
    return IsKeyPressed(Keyboard::W);
}

bool EventManager::IsSPressed()
{
    return IsKeyPressed(Keyboard::S);
}

bool EventManager::IsUpArrowPressed()
{
    return IsKeyPressed(Keyboard::Up);
}

bool EventManager::IsDownArrowPressed()
{
    return IsKeyPressed(Keyboard::Down);
}