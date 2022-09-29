#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
class NPCSeek
{
public:
	NPCSeek();

	void loadFiles();

	void update(sf::Time t_deltaTime, Player& t_player);

	void render(sf::RenderWindow& t_window);


	sf::Sprite seekSprite;

private:

	void seeking(Player &t_player, sf::Time t_deltaTime);

	sf::Vector2f velocity;

	sf::Texture seekTexture;

	//float angle = 0;
	const float PI = 3.141592654f;
	float speed = 6.0f;
};

