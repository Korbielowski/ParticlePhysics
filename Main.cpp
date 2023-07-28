#include <vector>
#include <random>
#include <iostream>

#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Button.h"

int main()
{
	const float particleRadius = 7;
	const float heightOffset = 2 * particleRadius;
	const unsigned windowHeight = 800;
	const unsigned windowWidth = 800;
	const sf::Color particleColor = sf::Color::Green;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Particle Simulation");
	sf::Event event;

	std::vector<Particle> particles;
	Button addParticleButton(200, 200, 200, 200, sf::Color::Red);

	std::random_device rd;
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	for (int i = 0; i < 4; i++)
		particles.push_back(Particle(dist(rd) * windowWidth, dist(rd) * windowHeight, 0.1f, 0.1f, particleRadius, particleColor));

	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
				if (addParticleButton.isMouseOver(window) && event.type == sf::Event::MouseButtonReleased) //Action not working
					std::cout << "Action done";
		/*	if(event.type == sf::Event::MouseButtonReleased && (sf::Mouse::getPosition().x >= addParticleButton.getPosition().x - ))*/
		}
		for (auto& particle : particles)
		{
			particle.moveParticle();
			particle.checkCollision(window);
			window.draw(particle.getShape());
			//std::cout << particle.getShape().getPosition().x << " " << particle.getShape().getPosition().y << std::endl;
		}
		window.draw(addParticleButton.getButton());
		//window.draw(addParticleButton.getText());
		window.display();
	}
	return 0;
}

