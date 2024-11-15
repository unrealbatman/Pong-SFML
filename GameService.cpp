#pragma once
#include "GameService.h"

GameService::GameService()
{
	timeService.Initialize();
	ball.SetUIServiceInBall(uiService); // TODO: This function needs to be changed. It should simple be a constructor or an initialization function rather than this.
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
	ball.BallUpdate(paddle.GetLeftPaddleSprite(), paddle.GetRightPaddleSprite(), timeService.GetDeltaTime()); 
}

void GameService::DrawGameObject(RenderWindow& window)
{
	// TODO: All these function must simply be named render()
	boundary.DrawBoundary(window);
	ball.DrawBall(window);
	paddle.DrawPaddle(window);
	uiService.DrawUI(window);
}