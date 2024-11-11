#pragma once
#include "Boundary.cpp"
#include "Ball.cpp"
#include "Paddle.cpp"
#include "TimeService.cpp"

class GameManager
{
private:
	Boundary boundary;
	Ball ball;
	Paddle paddle;
	TimeService timeService;

public:
	GameManager()
	{
		timeService.initialize();
	}

	void PlayGame(RenderWindow& window)
	{
		GameUpdate();
		DrawGameObject(window);
	}

	void GameUpdate()
	{
		timeService.update();
		paddle.MovePaddles();
		ball.MoveBall(paddle.GetLeftPaddleSprite(), paddle.GetRightPaddleSprite(), timeService.getDeltaTime());  // Move ball and check for collisions
	}

	void DrawGameObject(RenderWindow& window)
	{
		boundary.DrawBoundary(window);
		ball.DrawBall(window);
		paddle.DrawPaddle(window);
	}
};