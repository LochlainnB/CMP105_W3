#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle1.setRadius(50);
	circle1.setFillColor(sf::Color::Magenta);
	circle1.setPosition(0, 0);
	circle1Velocity.x = 400;
	circle1Velocity.y = 200;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	
}

// Update game objects
void Level::update(float dt)
{
	float targetX = circle1.getPosition().x + circle1Velocity.x * dt;
	float targetY = circle1.getPosition().y + circle1Velocity.y * dt;

	if (targetX < 0) {
		targetX = abs(targetX);
		circle1Velocity.x *= -1;
	}
	else if (targetX > window->getSize().x - 2 * circle1.getRadius()) {
		targetX = 2 * (window->getSize().x - 2 * circle1.getRadius()) - targetX;
		circle1Velocity.x *= -1;
	}
	if (targetY < 0) {
		targetY = abs(targetY);
		circle1Velocity.y *= -1;
	}
	else if (targetY > window->getSize().y - 2 * circle1.getRadius()) {
		targetY = 2 * (window->getSize().y - 2 * circle1.getRadius()) - targetY;
		circle1Velocity.y *= -1;
	}

	circle1.setPosition(targetX, targetY);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(circle1);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}