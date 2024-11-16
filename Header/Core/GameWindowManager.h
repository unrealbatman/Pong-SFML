#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Event/EventManager.h"
#include "../../Header/Gameplay/GameplayManager.h"
using namespace sf;
using namespace std;
using namespace Gameplay;

namespace Core
{
    class GameWindowManager
    {
    private:

        int game_window_width = 1280;
        int game_window_height = 720;
        string game_title = "SFML-Pong!";

        RenderWindow* game_window;
        EventManager* event_manager;
        GameplayManager* gameplay_manager;

        void createGameWindow();

    public:
        void initialize();
        bool isGameRunning();
        void pollEvents();
        void update();
        void render();
    };
}