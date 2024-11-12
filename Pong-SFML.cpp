#include <SFML/Graphics.hpp>
#include "GameService.h"
#include "EventService.h"
using namespace sf;

int main()
{
    RenderWindow window;
    EventService* eventService = new EventService();
    GameService* gameService = new GameService();

    window.create(VideoMode(1280, 720), "SFML-Pong!");

    while (window.isOpen())
    {
        eventService->EventPolling(window);

        window.clear();
        gameService->PlayGame(window);
        window.display();
    }
    return 0;
}