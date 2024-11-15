// TODO: Needs to be renamed as GameplayManager
// TODO: Remove PlayGame() method from the class it is redundant
// TODO: Rename GameUpdate to Update
// TODO: Rename DrawGameObject to Render
// TODO: Need to have pointer references for all the references instead of soft objects

#pragma once
#include "Boundary.h"
#include "Ball.h"
#include "Paddle.h"
#include "TimeService.h"
#include "UIService.h"

class GameService
{
private:
	int player1_position_x = 40;
	int player1_position_y = 300;

	int player2_postion_x = 1210;
	int player2_postion_y = 300;


	Boundary* boundary = new Boundary();
	Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
	Paddle* player2 = new Paddle(player2_postion_x, player2_postion_y);
	TimeService* timeService = new TimeService(); // TODO: Naming convention needs to be changed to time_service for variables. This needs to be done for all variabls in the project.
	UIService uiService;
	Ball* ball = new Ball(uiService);

public:
	GameService();

	void PlayGame(RenderWindow& window);

	void GameUpdate(); 
	// TODO: Naming convention needs to change here. The first letter of a method/function must be small cased. [gameUpdate()]
	// TODO: Change this everywhere in the project.


	void DrawGameObject(RenderWindow& window);
};