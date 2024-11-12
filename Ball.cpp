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

void Ball::MoveBall( float deltaTime)
{   
    UpdateBallDelayTime(deltaTime);
    pongBallSprite.move(velocity); 
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


    if (ballBounds.left <= 0 || ballBounds.left + ballBounds.width >= 1280) // Check for out-of-bounds (left or right)
    {
        ResetBall();
    }
}

void Ball::DrawBall(RenderWindow& window)
{
	window.draw(pongBallSprite);
}