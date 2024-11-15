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
	Boundary boundary;
	Paddle paddle;
	TimeService timeService; // TODO: Naming convention needs to be changed to time_service for variables. This needs to be done for all variabls in the project.
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