#pragma once
#include "GameplayManager.h"

GameplayManager::GameplayManager(EventManager* manager)
{
	time_service->initialize();
	event_manager = manager;
}

void GameplayManager::update()
{
	time_service->update();
	player1->update(event_manager->isWPressed(), event_manager->isSPressed());
	player2->update(event_manager->isUpArrowPressed(), event_manager->isDownArrowPressed());
	ball->update(player1, player2, time_service); 
	ui_service->update();
}

void GameplayManager::render(RenderWindow& window)
{
	boundary->render(window);
	ball->render(window);
	player1->render(window);
	player2->render(window);
	ui_service->render(window);
}