#pragma once
#include "Ball.h"

Ball::Ball()
{
    CreatePongBall();
}

void Ball::CreatePongBall()
{
    pongBallTexture.loadFromFile("Assets/Sprites/Ball.png");
    pongBallSprite.setTexture(pongBallTexture);
    pongBallSprite.setScale(0.2f, 0.2f);
    pongBallSprite.setPosition(615, 335);

    velocity = Vector2f(ballSpeed, ballSpeed);     // Initial velocity in a random direction
}

void Ball::ResetBall()
{
    pongBallSprite.setPosition(615, 335);
    velocity = Vector2f(ballSpeed, ballSpeed);
    delayedStart = true;         
    elapsedDelayTime = 0.0f;  
}

void Ball::UpdateBallDelayTime(float deltaTime)
{
    if (delayedStart)
    {
        elapsedDelayTime += deltaTime;
        if (elapsedDelayTime >= delayDuration)
        {
            delayedStart = false;
        }
        else
        {
            return;
        }
    }
}

void Ball::SetUIServiceInBall(UIService service)
{
    uiService = service;
}

void Ball::MoveBall(float deltaTime)
{   
    UpdateBallDelayTime(deltaTime);

    if (!delayedStart)
    {
        pongBallSprite.move(velocity * deltaTime * 100.0f);
    }
}

void Ball::OnBallCollision(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle)
{
    // Get ball bounds
    FloatRect ballBounds = pongBallSprite.getGlobalBounds();
    FloatRect leftPaddleBounds = leftPaddle.getGlobalBounds();
    FloatRect rightPaddleBounds = rightPaddle.getGlobalBounds();

    if (ballBounds.top <= 20 || ballBounds.top + ballBounds.height >= 700) // Check for collision with top and bottom boundaries (20-pixel boundaries)
    {
        velocity.y = -velocity.y;  // Reverse vertical direction
    }

    if (ballBounds.intersects(leftPaddleBounds) && velocity.x < 0)
    {
        velocity.x = -velocity.x;  // Reverse horizontal direction
    }

    if (ballBounds.intersects(rightPaddleBounds) && velocity.x > 0)
    {
        velocity.x = -velocity.x;  // Reverse horizontal direction
    }

    // Check for out-of-bounds on the left or right boundary
    if (ballBounds.left <= 0)
    {
        uiService.IncrementRightScore();
        ResetBall();
    }
    else if (ballBounds.left + ballBounds.width >= 1280)
    {
        uiService.IncrementLeftScore();
        ResetBall();
    }
}

void Ball::BallUpdate(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle, float deltaTime)
{
    MoveBall(deltaTime);
    OnBallCollision(leftPaddle, rightPaddle);
}

void Ball::DrawBall(RenderWindow& window)
{
	window.draw(pongBallSprite);
}