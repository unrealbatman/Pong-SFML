// TODO: There is no Folder Structure
// TODO: There are no Namespaces being used
// TODO: Need to create a GameWindowManager
// TODO: Game Window m ust be managed inside GameWindowManager class
// TODO: There is no Initialization Method in the main game loop

#include <SFML/Graphics.hpp>
#include "GameplayManager.h"
#include "EventManager.h"
using namespace sf;

int main()
{
    RenderWindow window;
    EventManager* event_manager = new EventManager();
    GameplayManager* gameplay_manager = new GameplayManager(event_manager);

    window.create(VideoMode(1280, 720), "SFML-Pong!");

    while (window.isOpen())
    {
        event_manager->eventPolling(window);

        window.clear();
        gameplay_manager->update();
        gameplay_manager->render(window);
        window.display();
    }
    return 0;
}