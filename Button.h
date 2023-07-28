#pragma once
#include <functional>
#include <iostream>

#include "SFML/Graphics.hpp"

class Button
{
public:
	Button(float sizeX, float sizeY, float posX, float posY, sf::Color btnColor);
	std::function<void()> onClick(std::function<void()>);
	bool isMouseOver(sf::RenderWindow& window);
	void setFont(sf::Font font);
	void setBtnColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setHoverColor(sf::Color color);
	sf::RectangleShape getButton() const;
	sf::Text getText() const;

private:
	float sizeX, sizeY;
	float posX, posY;
	sf::RectangleShape button;
	sf::Color btnColor;
	sf::Color hoverColor;
	sf::Color textColor;
	sf::Text text;
	sf::Font font;
};