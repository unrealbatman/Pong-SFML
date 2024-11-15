// TODO: A paddle class must represent and manage a single Paddle, not both of them!
// TODO: 2 objects of this class must have been created inside Gameplay Manager -> player_1_paddle & player_2_paddle


#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paddle
{
private:
	RectangleShape paddle_sprite;

	const float paddle_width = 20.0f;
	const float paddle_height = 140.0f;

	float paddleSpeed = 0.2f;
	float topBoundary = 20.0f;
	float bottomBoundary = 700.0f;

	void createPaddle(float position_x, float position_y);

public:
	Paddle(float position_x, float position_y);

	RectangleShape getPaddleSprite();

	void movePaddle();
	void update();
	void render(RenderWindow& window);
};