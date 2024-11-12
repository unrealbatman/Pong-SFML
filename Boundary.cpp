#include "Boundary.h"

void Boundary::CreateTopBoundary()
{
	topBoundary.setSize(Vector2f(1280.f, 20.f));
	topBoundary.setPosition(0.f, 0.f);
	topBoundary.setFillColor(Color::Blue);
}

void Boundary::CreateBottomBoundary()
{
	bottomBoundary.setSize(Vector2f(1280.f, 20.f));
	bottomBoundary.setPosition(0.f, 700.f);
	bottomBoundary.setFillColor(Color::Blue);
}

void Boundary::CreateLeftBoundary()
{
	leftBoundary.setSize(Vector2f(20.f, 720.f));
	leftBoundary.setPosition(0.f, 0.f);
	leftBoundary.setFillColor(Color::Blue);
}

void Boundary::CreateRightBoundary()
{
	rightBoundary.setSize(Vector2f(20.f, 720.f));
	rightBoundary.setPosition(1260.f, 0.f);
	rightBoundary.setFillColor(Color::Blue);
}

void Boundary::CreateCenterLine()
{
	centerLine.setSize(Vector2f(10, 680));
	centerLine.setPosition(640, 20);
	centerLine.setFillColor(Color::White);
}


Boundary::Boundary()
{
	CreateTopBoundary();
	CreateBottomBoundary();
	CreateLeftBoundary();
	CreateRightBoundary();
	CreateCenterLine();
}

void Boundary::DrawBoundary(RenderWindow& window)
{
	window.draw(topBoundary);
	window.draw(bottomBoundary);
	window.draw(leftBoundary);
	window.draw(rightBoundary);
	window.draw(centerLine);
}
