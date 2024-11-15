#include "Paddle.h"

Paddle::Paddle(float position_x, float position_y)
{
	createPaddle(position_x, position_y);
}

void Paddle::createPaddle(float position_x, float position_y)
{
	paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
	paddle_sprite.setPosition(position_x, position_y);
}

RectangleShape Paddle::getPaddleSprite()
{
	return paddle_sprite;
}

// TODO: All the inputs must have been fetched through the Event Manager rather then directly fetching here!
void Paddle::movePaddle()
{
	if (Keyboard::isKeyPressed(Keyboard::W) && paddle_sprite.getPosition().y > topBoundary)
	{
		paddle_sprite.move(0, -paddleSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && paddle_sprite.getPosition().y + paddle_sprite.getSize().y < bottomBoundary)
	{
		paddle_sprite.move(0, paddleSpeed);
	}

	/*if (Keyboard::isKeyPressed(Keyboard::Up) && rightPaddleSprite.getPosition().y > topBoundary)
	{
		rightPaddleSprite.move(0, -paddleSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && rightPaddleSprite.getPosition().y + rightPaddleSprite.getSize().y < bottomBoundary)
	{
		rightPaddleSprite.move(0, paddleSpeed);
	}*/
}

void Paddle::update() 
{
	movePaddle();
}

void Paddle::render(RenderWindow& window)
{
	window.draw(paddle_sprite);
}