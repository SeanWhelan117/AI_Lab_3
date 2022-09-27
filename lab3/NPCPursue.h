#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class NPCPursue
{
public:
	NPCPursue();

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);

	sf::Sprite pursueSprite;

private:


	sf::Texture pursueTexture;

	/*float angle = 0;
	float pi = 3.141592654f;
	int speed = 10;*/
};

