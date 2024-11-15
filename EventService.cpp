// TODO: Fetch for escape key input and if true then close the game window (Stop The Game)
// TODO: Why is this empty? Where are helper functions for fetching player inputs?

#include "EventService.h"

void EventService::EventPolling(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}