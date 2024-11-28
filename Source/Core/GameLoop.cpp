#include "../../Header/Core/GameLoop.h"

namespace Core
{
	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager();
		event_manager = new EventManager();
		gameplay_manager = new GameplayManager(event_manager);
		sound_manager = new SoundManager();

		game_window_manager->initialize();

		SoundManager::PlayBackgroundMusic();
	}

	GameLoop::~GameLoop()
	{
		delete game_window_manager;
		delete event_manager;
		delete gameplay_manager;
		delete sound_manager;
	}

	bool GameLoop::isGameRunning()
	{
		return game_window_manager->isGameOpen();
	}

	void GameLoop::pollEvent()
	{
		event_manager->pollEvents(game_window_manager->getGameWindow());
	}

	void GameLoop::update()
	{
		gameplay_manager->update();
	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();
		gameplay_manager->render(game_window_manager->getGameWindow());
		game_window_manager->displayGameWindow();
	}
}