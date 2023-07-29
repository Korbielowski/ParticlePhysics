#pragma once
#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle(float x, float y, float velX, float velY, int radius, sf::Color color);
	void checkCollision(const sf::RenderWindow& window);
	void moveParticle();
	void setRadius(float radius);
	void setPosX(float posX);
	void setPosY(float posY);
	void setVelX(float velX);
	void setVelY(float velY);
	void setColor(sf::Color color);
	float getVelX() const;
	float getVelY() const;
	float getPosX() const;
	float getPosY() const;
	sf::CircleShape getShape() const;

private:
	float velX, velY;
	float posX, posY;
	//float mass; Add mass of a particle/object
	int radius;
	sf::Color color;
	sf::CircleShape particleShape;
};