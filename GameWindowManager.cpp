#include "GameWindowManager.h"

void GameWindowManager::createGameWindow(int width, int height, const string& title)
{
    window.create(VideoMode(width, height), title);
}

void GameWindowManager::initialize(int width, int height, const string& title)
{
    event_manager = new EventManager();
    gameplay_manager = new GameplayManager(event_manager);

    createGameWindow(width, height, title);
}

void GameWindowManager::gameLoop()
{
    while (window.isOpen()) 
    {
        pollEvents();

        window.clear();
        update();
        render();
        window.display();
    }
}

void GameWindowManager::pollEvents()
{
    event_manager->eventPolling(window);
}

void GameWindowManager::update()
{
    gameplay_manager->update();
}

void GameWindowManager::render()
{
    gameplay_manager->render(window);
}