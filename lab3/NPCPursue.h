#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h";

class NPCPursue
{
public:
	NPCPursue();

	void loadFiles();

	void update(sf::Time t_deltaTime, Player& t_player);

	void render(sf::RenderWindow& t_window);


	sf::Sprite pursueSprite;

private:

	void pursuing(Player& t_player);

	sf::Texture pursueTexture;

	const float PI = 3.141592654f;
	sf::Vector2f velocity;

	float speed = 8.0f;
	float lowerSpeed = 3.0f;

	float ogSpeed = 0;

};

