// TODO: Need pointer references instead of soft objects
// TODO: Update and Render function missing
// TODO: Why is the ball taking care of UI Management? It does not make sense. Ideally the Gameplay Manager should be the one responsible for managing gameplay UI.
// TODO: Remove "Ball" from each method name

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
    bool delayedStart = true; // TODO: What is this bool being used for? Why are we not using Enums for this (BallState)?
    float elapsedDelayTime = 0.0f;

    void CreatePongBall();
    void ResetBall();
    void UpdateBallDelayTime(float deltaTime);

public:

    Ball();

    void SetUIServiceInBall(UIService service); // TODO: Not needed, pass the dependencies through a constructor

    void MoveBall(float deltaTime);
    void OnBallCollision(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle);

    void BallUpdate(const RectangleShape& leftPaddle, const RectangleShape& rightPaddle, float deltaTime);
    void DrawBall(RenderWindow& window);
};