#pragma once
#include "Boundary.h"
#include "Ball.h"
#include "Paddle.h"
#include "TimeService.h"
#include "UIService.h"
#include "EventManager.h"

class GameplayManager
{
private:
	float player1_position_x = 40.0f;
	float player1_position_y = 300.0f;

	float player2_postion_x = 1210.0f;
	float player2_postion_y = 300.0f;

	EventManager* event_manager;
	TimeService* time_service = new TimeService();
	UIService* ui_service = new UIService;
	Boundary* boundary = new Boundary();
	Ball* ball = new Ball();
	Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
	Paddle* player2 = new Paddle(player2_postion_x, player2_postion_y);

public:
	GameplayManager(EventManager* manager);

	void updatePlayerScore();

	void update(); 
	void render(RenderWindow& window);
};