#pragma once
#include "Ball.h"

Ball::Ball()
{
    CreatePongBall(); // TODO: function needs to be renamed -> loadTexture(); initializeVariabls(); 
}

void Ball::CreatePongBall()
{
    pongBallTexture.loadFromFile("Assets/Sprites/Ball.png"); // TODO: Magic string
    pongBallSprite.setTexture(pongBallTexture);
    pongBallSprite.setScale(0.2f, 0.2f); // TODO: Magic Numbers
    pongBallSprite.setPosition(615, 335); // TODO: Magic Numbers

    velocity = Vector2f(ballSpeed, ballSpeed);     // Initial velocity in a random direction
}

void Ball::ResetBall() // TODO: Simply call it reset(). It is already inside the Ball class so everyone will know what is being reset, no need to mention in the name.
{ 
    pongBallSprite.setPosition(615, 335); // TODO: Magic Numbers
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

    if (!delayedStart) // TODO: Need to change this bool into enum states. Readability can not be compromised.
    {
        pongBallSprite.move(velocity * deltaTime * 100.0f); // TODO: Magic Numbers
    }
}

// TODO: Need helper functions inside this collision method. Need to segregate logic and follow SRP
void Ball::OnBallCollision(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle)
{
    // Get ball bounds
    FloatRect ballBounds = pongBallSprite.getGlobalBounds();
    FloatRect leftPaddleBounds = leftPaddle.getGlobalBounds();
    FloatRect rightPaddleBounds = rightPaddle.getGlobalBounds();

    // TODO: Magic Numbers
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
    else if (ballBounds.left + ballBounds.width >= 1280) // TODO: Magic Numbers
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