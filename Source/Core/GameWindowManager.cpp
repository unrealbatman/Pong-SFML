#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
    void GameWindowManager::initialize()
    {
        game_window = new RenderWindow();
        event_manager = new EventManager();
        gameplay_manager = new GameplayManager(event_manager);

        createGameWindow();
    }

    void GameWindowManager::createGameWindow()
    {
        game_window->create(VideoMode(game_window_width, game_window_height), game_title);
    }

    bool GameWindowManager::isGameRunning()
    { 
        return game_window->isOpen();
    }

    void GameWindowManager::pollEvents()
    {
        event_manager->eventPolling(game_window);
    }

    void GameWindowManager::update()
    {
        gameplay_manager->update();
    }

    void GameWindowManager::render()
    {
        game_window->clear();
        gameplay_manager->render(game_window);
        game_window->display();
    }
}