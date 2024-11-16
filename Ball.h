// TODO: Why is the ball taking care of UI Management? It does not make sense. Ideally the Gameplay Manager should be the one responsible for managing gameplay UI.

#pragma once
#include <SFML/Graphics.hpp>
#include "UIService.h"
#include "Paddle.h"
#include "TimeService.h"
using namespace sf;

enum class BallState
{
    Idle, 
    Moving
};

class Ball
{
private:
    Texture pong_ball_texture;
    Sprite pong_ball_sprite;
    UIService* ui_service;

    string texture_path = "Assets/Sprites/Ball.png";

    const float scale_x = 0.2f;
    const float scale_y = 0.2f;

    const float position_x = 615.0f;
    const float position_y = 335.0f;

    Vector2f velocity;   // Velocity vector for ball movement
    const float ball_speed = 5.0f;
    const float speed_multiplier = 100.0f;

    float delay_duration = 2.0f;
    BallState current_state = BallState::Idle; // Initialize the ball's state
    float elapsed_delay_time = 0.0f;

    const float top_boundary = 20.0f;
    const float bottom_boundary = 700.0f;
    const float left_boundary = 0.0f;
    const float right_boundary = 1280.0f;

    void loadTexture();
    void initializeVariables();
    void reset();
    void updateDelayTime(float deltaTime);

public:

    Ball(UIService* service);

    void move(TimeService* timeService);

    void handleBoudaryCollision();
    void handlePaddleCollision(Paddle* player1, Paddle* player2);
    void handleOutofBoundCollision();
    
    void onCollision(Paddle* player1, Paddle* player2);
    void update(Paddle* player1, Paddle* player2, TimeService* timeService);
    void render(RenderWindow& window);
};