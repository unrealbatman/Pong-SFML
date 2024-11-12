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