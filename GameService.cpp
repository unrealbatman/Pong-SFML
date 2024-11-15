#pragma once
#include "GameService.h"

GameService::GameService()
{
	timeService->Initialize();
}

void GameService::PlayGame(RenderWindow& window)
{
	GameUpdate();
	DrawGameObject(window);
}

void GameService::GameUpdate()
{
	timeService->Update();
	player1->update();
	player2->update();
	ball->update(player1, player2, timeService); 
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