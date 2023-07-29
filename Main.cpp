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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				if (addParticleButton.isMouseOver(window))
					break;
			case sf::Event::MouseButtonReleased:
				if (addParticleButton.isMouseOver(window))
					std::cout << "Action done" << std::endl;
				break;
			}
		}

		for (auto& particle : particles)
		{
			particle.moveParticle();
			particle.checkCollision(window);
			window.draw(particle.getShape());
		}
		window.draw(addParticleButton.getButton());
		//window.draw(addParticleButton.getText());
		window.display();
	}
	return 0;
}