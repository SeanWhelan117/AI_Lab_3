#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class NPCSeek
{
public:
	NPCSeek();

	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);

	sf::Sprite seekSprite;

private:


	sf::Texture seekTexture;

	/*float angle = 0;
	float pi = 3.141592654f;
	int speed = 10;*/
};

