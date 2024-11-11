#include <SFML/Graphics.hpp>
using namespace sf;

class EventPollingManager
{
private:

public:
    EventPollingManager()
    {

    }

    void EventPolling(RenderWindow& window)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
};