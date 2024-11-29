#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Event {
    class EventManager {
    public:
        void pollEvents(sf::RenderWindow* game_window);

        bool isKeyPressed(sf::Keyboard::Key key);
    };
}
