#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class UIService
{
private:
    
    Font font;
    Text leftScoreText;
    Text rightScoreText;

    int leftScore = 0; // TODO: Should be Player 1 score &* Player 3 score instead of left and right
    int rightScore = 0;

    string FormatScore(int score);

    void CreateLeftScoreText();
    void CreateRightScoreText();

public:

	UIService();

    void IncrementLeftScore();
    void IncrementRightScore();

    void DrawUI(RenderWindow& window); // TODO: render()
};