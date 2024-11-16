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
	player1->update(event_manager->IsWPressed(), event_manager->IsSPressed());
	player2->update(event_manager->IsUpArrowPressed(), event_manager->IsDownArrowPressed());
	ball->update(player1, player2, time_service); 
}

void GameService::DrawGameObject(RenderWindow& window)
{
	// TODO: All these function must simply be named render()
	boundary->render(window);
	ball->render(window);
	player1->render(window);
	player2->render(window);
	uiService.DrawUI(window);
}