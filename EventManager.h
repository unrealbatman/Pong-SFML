#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class EventManager
{
private:
    bool IsKeyPressed(Keyboard::Key key); 

public:
    void EventPolling(RenderWindow& window);

    bool IsWPressed();
    bool IsSPressed();
    bool IsUpArrowPressed();
    bool IsDownArrowPressed();
};