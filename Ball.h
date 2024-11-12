#pragma once
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
    Texture pongBallTexture;
    Sprite pongBallSprite;

    Vector2f velocity;   // Velocity vector for ball movement
    float ballSpeed = 0.1f;
    float delayDuration = 2.0f;
    bool delayedStart = true;
    float elapsedDelayTime = 0.0f;

    void CreatePongBall();
    void ResetBall();
    void UpdateBallDelayTime(float deltaTime);

public:

    Ball();

    void MoveBall(float deltaTime);
    void OnBallCollision(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle);

    void DrawBall(RenderWindow& window);
};