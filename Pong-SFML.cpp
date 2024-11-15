// TODO: Rename this to main.cpp
// TODO: There is no Folder Structure
// TODO: There are no Namespaces being used
// TODO: Naming needs to be changed from EventService and GameService to EventManager & GameplayManager
// TODO: Need to create a GameWindowManager
// TODO: Update & Render funtions are missing from the main game loop
// TODO: Game Window m ust be managed inside GameWindowManager class
// TODO: There is no Initialization Method in the main game loop

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