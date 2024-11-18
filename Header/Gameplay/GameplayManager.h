#pragma once
#include "../../Header/Gameplay/Ball/Ball.h"
#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay
{
	class GameplayManager
	{
	private:
		float player1_position_x = 40.0f;
		float player1_position_y = 300.0f;

		float player2_postion_x = 1210.0f;
		float player2_postion_y = 300.0f;

		Ball* ball = new Ball();
		Paddle* player1 = new Paddle(player1_position_x, player1_position_y);
		Paddle* player2 = new Paddle(player2_postion_x, player2_postion_y);

	public:
		GameplayManager();

		void update();
		void render(RenderWindow* game_window);
	};
}