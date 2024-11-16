#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Event
{
    class EventManager
    {
    private:
        bool isKeyPressed(Keyboard::Key key);

    public:
        void eventPolling(RenderWindow* game_window);

        bool isWPressed();
        bool isSPressed();
        bool isUpArrowPressed();
        bool isDownArrowPressed();
    };
}