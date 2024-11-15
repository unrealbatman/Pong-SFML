#pragma once
#include "GameService.h"

GameService::GameService()
{
	timeService.Initialize();
}

void GameService::PlayGame(RenderWindow& window)
{
	GameUpdate();
	DrawGameObject(window);
}

void GameService::GameUpdate()
{
	timeService.Update();
	paddle.MovePaddles(); // TODO: paddle.update()
	// TODO: ball.update()
	// TODO: only references of paddle & timeservice needs to be passed on.
	ball->update(paddle, paddle, timeService); 
}

void GameService::DrawGameObject(RenderWindow& window)
{
	// TODO: All these function must simply be named render()
	boundary.DrawBoundary(window);
	ball->render(window);
	paddle.DrawPaddle(window);
	uiService.DrawUI(window);
}