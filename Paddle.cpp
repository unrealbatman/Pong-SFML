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

	void CreateLeftPaddle()
	{
		leftPaddleSprite.setSize(Vector2f(20, 140));
		leftPaddleSprite.setPosition(40, 300);
	}

	void CreateRightPaddle()
	{
		rightPaddleSprite.setSize(Vector2f(20, 140));
		rightPaddleSprite.setPosition(1210, 300);
	}

public:
	Paddle()
	{
		CreateLeftPaddle();
		CreateRightPaddle();
	}

	RectangleShape GetLeftPaddleSprite()
	{
		return leftPaddleSprite;
	}

	RectangleShape GetRightPaddleSprite()
	{
		return rightPaddleSprite;
	}

	void MovePaddles()
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

	void DrawPaddle(RenderWindow& window)
	{
		window.draw(leftPaddleSprite);
		window.draw(rightPaddleSprite);
	}
};