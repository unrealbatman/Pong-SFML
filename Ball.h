#pragma once
#include <SFML/Graphics.hpp>
#include "UIService.h"
using namespace sf;

class Ball
{
private:
    Texture pongBallTexture;
    Sprite pongBallSprite;
    UIService uiService;

    Vector2f velocity;   // Velocity vector for ball movement
    float ballSpeed = 5.0f;
    float delayDuration = 2.0f;
    bool delayedStart = true;
    float elapsedDelayTime = 0.0f;

    void CreatePongBall();
    void ResetBall();
    void UpdateBallDelayTime(float deltaTime);

public:

    Ball();

    void SetUIServiceInBall(UIService service);

    void MoveBall(float deltaTime);
    void OnBallCollision(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle);

    void BallUpdate(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle, float deltaTime);
    void DrawBall(RenderWindow& window);
};