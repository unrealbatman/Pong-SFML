// TODO: A paddle class must represent and manage a single Paddle, not both of them!
// TODO: 2 objects of this class must have been created inside Gameplay Manager -> player_1_paddle & player_2_paddle


#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paddle
{
private:
	RectangleShape leftPaddleSprite;
	RectangleShape rightPaddleSprite;
	float paddleSpeed = 0.2f;
	float topBoundary = 20.0f;
	float bottomBoundary = 700.0f;

	void CreateLeftPaddle();
	void CreateRightPaddle();

public:
	Paddle();

	RectangleShape GetLeftPaddleSprite();
	RectangleShape GetRightPaddleSprite();

	void MovePaddles();

	void DrawPaddle(RenderWindow& window);
};