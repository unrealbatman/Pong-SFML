#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Ball
{
private:
	Texture pongBallTexture;
	Sprite pongBallSprite;

    Vector2f velocity;   // Velocity vector for ball movement
    float ballSpeed = 0.1f; // Initial speed of the ball
    float delayDuration = 2.0f;  // 1 second delay
    bool delayedStart = true;
    float elapsedDelayTime = 0.0f;

	void CreatePongBall()
	{
		pongBallTexture.loadFromFile("Assets/Sprites/Ball.png");
		pongBallSprite.setTexture(pongBallTexture);
		pongBallSprite.setScale(0.2f, 0.2f);
		pongBallSprite.setPosition(615, 335);

        // Initial velocity in a random direction
        velocity = Vector2f(ballSpeed, ballSpeed);
	}

    // Reset ball to center and start delay
    void ResetBall()
    {
        pongBallSprite.setPosition(615, 335);
        velocity = Vector2f(ballSpeed, ballSpeed);
        delayedStart = true;          // Enable delay
        elapsedDelayTime = 0.0f;      // Reset elapsed delay time
    }

public:
	Ball()
	{
		CreatePongBall();
	}

    void MoveBall(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle, float deltaTime)
    {
        // Update delay time if delayedStart is enabled
        if (delayedStart)
        {
            elapsedDelayTime += deltaTime;
            std::cout << elapsedDelayTime;
            if (elapsedDelayTime >= delayDuration)
            {
                delayedStart = false;  // End delay
            }
            else
            {
                return;  // Exit without moving the ball until delay is over
            }
        }

        // Update ball position
        pongBallSprite.move(velocity);

        // Get ball bounds
        FloatRect ballBounds = pongBallSprite.getGlobalBounds();
        FloatRect leftPaddleBounds = leftPaddle.getGlobalBounds();
        FloatRect rightPaddleBounds = rightPaddle.getGlobalBounds();

        // Check for collision with top and bottom boundaries (20-pixel boundaries)
        if (ballBounds.top <= 20 || ballBounds.top + ballBounds.height >= 700)
        {
            velocity.y = -velocity.y;  // Reverse vertical direction
        }

        // Check for collision with left paddle
        if (ballBounds.intersects(leftPaddleBounds) && velocity.x < 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction
        }

        // Check for collision with right paddle
        if (ballBounds.intersects(rightPaddleBounds) && velocity.x > 0)
        {
            velocity.x = -velocity.x;  // Reverse horizontal direction
        }

        // Check for out-of-bounds (left or right)
        if (ballBounds.left <= 0 || ballBounds.left + ballBounds.width >= 1280)
        {
            ResetBall();  // Reset ball and start delay
        }
    }

	void DrawBall(RenderWindow& window)
	{
		window.draw(pongBallSprite);
	}
};