#pragma once
#include "Boundary.h"
#include "Ball.h"
#include "Paddle.h"
#include "TimeService.h"
#include "UIService.h"

class GameService
{
private:
	Boundary boundary;
	Ball ball;
	Paddle paddle;
	TimeService timeService;
	UIService uiService;

public:
	GameService();

	void PlayGame(RenderWindow& window);

	void GameUpdate();

	void DrawGameObject(RenderWindow& window);
};