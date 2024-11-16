#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class EventManager
{
private:
    bool isKeyPressed(Keyboard::Key key); 

public:
    void eventPolling(RenderWindow& window);

    bool isWPressed();
    bool isSPressed();
    bool isUpArrowPressed();
    bool isDownArrowPressed();
};