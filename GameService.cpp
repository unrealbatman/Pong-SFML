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
	paddle.MovePaddles();
	ball.MoveBall(timeService.GetDeltaTime());
	ball.OnBallCollision(paddle.GetLeftPaddleSprite(), paddle.GetRightPaddleSprite());
}

void GameService::DrawGameObject(RenderWindow& window)
{
	boundary.DrawBoundary(window);
	ball.DrawBall(window);
	paddle.DrawPaddle(window);
}