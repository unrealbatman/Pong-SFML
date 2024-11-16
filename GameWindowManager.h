#pragma once
#include <SFML/Graphics.hpp>
#include "EventManager.h"
#include "GameplayManager.h"
using namespace sf;

class GameWindowManager 
{
private:
    RenderWindow window;
    EventManager* event_manager;
    GameplayManager* gameplay_manager;

    void createGameWindow(int width, int height, const string& title);

public:
    void initialize(int width, int height, const string& title);
    void gameLoop();
    void pollEvents();
    void update();
    void render();
};