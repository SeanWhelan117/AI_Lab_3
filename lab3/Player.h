#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	void loadFiles();

	void update(sf::Time t_deltaTime);

	void render(sf::RenderWindow& t_window);

	sf::Sprite playerSprite;

	int playerOffset = 16;

private:
	void playerInput(sf::Time t_deltaTime);
	void rotatePlayer(int t_rotation);

	void movePlayer();
	sf::Texture playerTexture;

	//sf::Vector2f speed;
	int speed = 10;
};

