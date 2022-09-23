#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	void loadFiles();

	void update();

	void render(sf::RenderWindow& t_window);

	sf::Sprite playerSprite;

private:
	void playerInput();
	void rotatePlayer(int t_rotation);

	void movePlayer();
	sf::Texture playerTexture;

	sf::Vector2f speed;
};

