#pragma once
#include "GameService.h"

GameService::GameService()
{
	timeService.Initialize();
	ball.SetUIServiceInBall(uiService);
}

void GameService::PlayGame(RenderWindow& window)
{
	GameUpdate();
	DrawGameObject(window);
}

void GameService::GameUpdate()
{
	timeService.Update();
	paddle.MovePaddles();
	ball.BallUpdate(paddle.GetLeftPaddleSprite(), paddle.GetRightPaddleSprite(), timeService.GetDeltaTime());
}

void GameService::DrawGameObject(RenderWindow& window)
{
	boundary.DrawBoundary(window);
	ball.DrawBall(window);
	paddle.DrawPaddle(window);
	uiService.DrawUI(window);
}