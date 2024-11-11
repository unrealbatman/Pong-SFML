#include <SFML/Graphics.hpp>
#include "GameManager.cpp"
#include "EventPollingManager.cpp"
using namespace sf;

int main()
{
    RenderWindow window;
    EventPollingManager* eventPolling = new EventPollingManager();
    GameManager* gameManager = new GameManager();

    window.create(VideoMode(1280, 720), "SFML-Pong!");

    while (window.isOpen())
    {
        eventPolling->EventPolling(window);

        window.clear();
        gameManager->PlayGame(window);
        window.display();
    }
    return 0;
}