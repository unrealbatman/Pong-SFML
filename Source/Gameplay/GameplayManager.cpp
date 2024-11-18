#pragma once
#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager() {}

	void GameplayManager::update() {}

	void GameplayManager::render(RenderWindow* game_window)
	{
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
	}
}