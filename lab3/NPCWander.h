#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class NPCWander
{
public:
	NPCWander();

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);

	sf::Sprite wanderSprite;

	int wanderOffset = 16;


private:
	void wandering(sf::Time t_deltaTime);

	void setUpVisionCone();

	void updateVisionCone();

	
	sf::Texture wanderTexture;

	float angle = 0;
	float pi = 3.141592654f;
	float speed = 10.0f;

	int radiusVC = 5;

	sf::Vertex lineLeft[2];
	sf::Vertex lineRight[2];

	float visionConeLeftX;
	float visionConeLeftY;

	float visionConeRightX;
	float visionConeRightY;


};

