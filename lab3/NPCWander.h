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

private:
	void wanderSetup();
	sf::Texture wanderTexture;
};

