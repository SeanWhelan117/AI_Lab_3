#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
class NPCArrive
{
public:
	NPCArrive();

	void loadFiles();

	void update(Player& t_player,  sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);


	sf::Sprite arriveSprite;

	void setSpeed(int t_speed);
private:
	void arriving(Player& t_player, sf::Time t_deltaTime);



	sf::Texture arriveTexture;

	sf::Vector2f velocity;


	const float PI = 3.141592654f;
	float speed = 8.0f;
	float lowerSpeed = 3.0f;

	float ogSpeed = 0;

};

