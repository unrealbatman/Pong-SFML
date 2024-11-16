#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Events/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
using namespace sf;
using namespace std;

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