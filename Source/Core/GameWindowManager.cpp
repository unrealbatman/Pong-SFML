#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
    void GameWindowManager::initialize()
    {
        game_window = new RenderWindow();

        createGameWindow();
    }

    void GameWindowManager::createGameWindow()
    {
        game_window->create(VideoMode(game_window_width, game_window_height), game_title);
    }

    RenderWindow* GameWindowManager::getGameWindow()
    {
        return game_window;
    }

    bool GameWindowManager::isGameRunning()
    { 
        return game_window->isOpen();
    }

    void GameWindowManager::update() {}

    void GameWindowManager::render()
    {
        game_window->clear();

        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);
        game_window->draw(shape);

        game_window->display();
    }
}