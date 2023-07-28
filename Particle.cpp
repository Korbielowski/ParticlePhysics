#include <iostream>

#include "Particle.h"

Particle::Particle(float x, float y, float velX, float velY, int radius, sf::Color color): posX(x), posY(y), velX(velX), velY(velY), radius(radius), color(color)
{
	particleShape.setRadius(this->radius);
	particleShape.setOrigin(this->radius, -this->radius);
	particleShape.setPosition(this->posX, this->posY);
	particleShape.setFillColor(this->color);
	std::cout << "Object created" << std::endl;
}

void Particle::checkCollision(const sf::RenderWindow& window)
{
	const unsigned windowWidth = window.getSize().x;
	const unsigned windowHeight = window.getSize().y;
	const float heightOffset = 2 * radius;

	if (posX + radius >= windowWidth || posX - radius <= 0)
		velX = velX * -1;
	if (posY + radius + heightOffset >= windowHeight || posY + radius <= 0)
		velY = velY * -1;
}

void Particle::moveParticle()
{
	posX += velX;
	posY += velY;
	particleShape.setPosition(posX, posY);
}

void Particle::setRadius(float radius)
{
	this->radius = radius;
}

void Particle::setPosX(float posX)
{
	this->posX = posX;
}

void Particle::setPosY(float posY)
{
	this->posY = posY;
}

void Particle::setVelX(float velX)
{
	this->velX = velX;
}

void Particle::setVelY(float velY)
{
	this->velY = velY;
}

void Particle::setColor(sf::Color color)
{
	this->color = color;
}

float Particle::getVelX() const
{
	return velX;
}

float Particle::getVelY() const
{
	return velY;
}

float Particle::getPosX() const
{
	return posX;
}

float Particle::getPosY() const
{
	return posY;
}

sf::CircleShape Particle::getShape() const
{
	return particleShape;
}