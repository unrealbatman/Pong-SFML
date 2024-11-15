#include "Paddle.h"

Paddle::Paddle()
{
	CreateLeftPaddle();
	CreateRightPaddle();
}

void Paddle::CreateLeftPaddle()
{
	leftPaddleSprite.setSize(Vector2f(20, 140)); // TODO: Magic Numbers
	leftPaddleSprite.setPosition(40, 300); // TODO: Magic Numbers
}

void Paddle::CreateRightPaddle()
{
	rightPaddleSprite.setSize(Vector2f(20, 140)); // TODO: Magic Numbers
	rightPaddleSprite.setPosition(1210, 300); // TODO: Magic Numbers
}

RectangleShape Paddle::GetLeftPaddleSprite()
{
	return leftPaddleSprite;
}

RectangleShape Paddle::GetRightPaddleSprite()
{
	return rightPaddleSprite;
}


// TODO: All the inputs must have been fetched through the Event Manager rather then directly fetching here!
void Paddle::MovePaddles()
{
	if (Keyboard::isKeyPressed(Keyboard::W) && leftPaddleSprite.getPosition().y > topBoundary)
	{
		leftPaddleSprite.move(0, -paddleSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && leftPaddleSprite.getPosition().y + leftPaddleSprite.getSize().y < bottomBoundary)
	{
		leftPaddleSprite.move(0, paddleSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && rightPaddleSprite.getPosition().y > topBoundary)
	{
		rightPaddleSprite.move(0, -paddleSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && rightPaddleSprite.getPosition().y + rightPaddleSprite.getSize().y < bottomBoundary)
	{
		rightPaddleSprite.move(0, paddleSpeed);
	}
}

void Paddle::DrawPaddle(RenderWindow& window)
{
	window.draw(leftPaddleSprite);
	window.draw(rightPaddleSprite);
}