#include "UIService.h"
#include <iostream>

UIService::UIService()
{
    font.loadFromFile("Assets/Fonts/Aloevera-OVoWO.ttf");
    CreateLeftScoreText();
    CreateRightScoreText();
}

void UIService::CreateLeftScoreText()
{
    leftScoreText.setFont(font);
    leftScoreText.setString("00");
    leftScoreText.setCharacterSize(40);
    leftScoreText.setFillColor(Color::White);
    leftScoreText.setPosition(580, 30);
}

void UIService::CreateRightScoreText()
{
    rightScoreText.setFont(font);
    rightScoreText.setString("00");
    rightScoreText.setCharacterSize(40);
    rightScoreText.setFillColor(Color::White);
    rightScoreText.setPosition(660, 30);
}


string UIService::FormatScore(int score)
{
    return (score < 10 ? "0" : "") + to_string(score); // Ensure scores display with two digits (e.g., 00, 01, 10)
}

void UIService::IncrementLeftScore()
{
    cout << "Left Before Incrementing" <<leftScore <<endl;
    leftScore++;
    cout <<"Left After Incrementing" << leftScore << endl;
    leftScoreText.setString(FormatScore(leftScore));
}

void UIService::IncrementRightScore()
{
    cout << "Right Before Incrementing" << rightScore <<endl;
    rightScore++;
    cout << "Right After Incrementing" << rightScore <<endl;
    rightScoreText.setString(FormatScore(rightScore));
}

void UIService::DrawUI(RenderWindow& window)
{
    window.draw(leftScoreText);
    window.draw(rightScoreText);
}