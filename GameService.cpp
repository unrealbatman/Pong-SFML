#pragma once
#include "GameService.h"

GameService::GameService(EventManager* manager)
{
	time_service->Initialize();
	event_manager = manager;
}

void GameService::PlayGame(RenderWindow& window)
{
	GameUpdate();
	DrawGameObject(window);
}

void GameService::GameUpdate()
{
	time_service->Update();
	player1->update(event_manager->isWPressed(), event_manager->isSPressed());
	player2->update(event_manager->isUpArrowPressed(), event_manager->isDownArrowPressed());
	ball->update(player1, player2, time_service); 
	ui_service->update();
}

void GameService::DrawGameObject(RenderWindow& window)
{
	// TODO: All these function must simply be named render()
	boundary->render(window);
	ball->render(window);
	player1->render(window);
	player2->render(window);
	ui_service->render(window);
}