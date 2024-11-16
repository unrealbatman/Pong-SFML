// TODO: There is no Folder Structure
// TODO: There are no Namespaces being used

#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameWindowManager.h"
using namespace sf;

int main()
{
    int screen_width = 1280;
    int screen_length = 720;
    string game_title = "SFML-Pong!";

    GameWindowManager * game_window_manager = new GameWindowManager();
    game_window_manager->initialize(screen_width, screen_length, game_title);
    game_window_manager->gameLoop();

    return 0;
}