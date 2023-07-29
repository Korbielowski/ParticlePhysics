#include "Button.h"

Button::Button(float sizeX, float sizeY, float posX, float posY, sf::Color btnColor): sizeX(sizeX), sizeY(sizeY), posX(posX), posY(posY), btnColor(btnColor)
{
	button.setSize(sf::Vector2f(this->sizeX, this->sizeY));
	button.setOrigin(0.5f * this->sizeX, 0.5f * this->sizeY);
	button.setPosition(this->posX, this->posY);
	button.setFillColor(this->btnColor);
	
	text.setCharacterSize(14);
	text.setPosition(sf::Vector2f(this->sizeX, this->sizeY));
	text.setFillColor(sf::Color::Magenta);
}

void Button::setBtnColor(sf::Color color)
{
	btnColor = color;
	button.setFillColor(btnColor);
}

void Button::setTextColor(sf::Color color)
{
	textColor = color;
}

void Button::setHoverColor(sf::Color color)
{
	hoverColor = color;
}

void Button::setFont(sf::Font font)
{
	this->font = font;
}


std::function<void()> Button::onClick(std::function<void()> function)
{
	std::cout << "Button Clicked";
	return function;
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	float mousePosX = sf::Mouse::getPosition(window).x;
	float mousePosY = sf::Mouse::getPosition(window).y;
	if (mousePosX > posX - 0.5f * sizeX && mousePosX < posX + 0.5f * sizeX && mousePosY > posY - 0.5f * sizeY && mousePosY < posY + 0.5f * sizeY)
	{ 
		this->setBtnColor(sf::Color::Green);
		return true;
	}
	else
	{
		this->setBtnColor(sf::Color::Red);
		return false;
	}
		
}

sf::RectangleShape Button::getButton() const
{
	return button;
}

sf::Text Button::getText() const
{
	return text;
}