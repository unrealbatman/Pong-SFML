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