// TODO: Update Render missing

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Boundary
{
private:
	RectangleShape topBoundary;
	RectangleShape bottomBoundary;
	RectangleShape leftBoundary;
	RectangleShape rightBoundary;
	RectangleShape centerLine;

	void CreateTopBoundary();
	void CreateBottomBoundary();
	void CreateLeftBoundary();
	void CreateRightBoundary();

	void CreateCenterLine();

public:
	Boundary();

	void DrawBoundary(RenderWindow& window);
};
