#include "../../Header/Core/GameWindowManager.h"

void Core::GameWindowManager::createGameWindow()
{
	game_window->create(
		VideoMode(game_window_width, game_window_height),
		game_title
	);
}

void Core::GameWindowManager::initialize()
{

	game_window = new RenderWindow();
	createGameWindow();
}

RenderWindow* Core::GameWindowManager::getGameWindow()
{
	return game_window;
}

bool Core::GameWindowManager::isGameRunning()
{
	return game_window->isOpen();
}

void Core::GameWindowManager::render()
{
}
