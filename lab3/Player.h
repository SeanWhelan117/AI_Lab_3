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

	sf::Vector2f getHeadingPoint();
private:
	void playerInput(sf::Time t_deltaTime);
	void rotatePlayer(int t_rotation);

	void movePlayer(sf::Time t_deltaTime);

	void setupPlayerCircle();


	sf::Texture playerTexture;

	sf::CircleShape playerCircle;
	int playerCircleRadius = 100;
	float velocityX;
	float velocityY;
	//sf::Vector2f speed;
	int speed = 0;
	int maxSpeed = 15;

};

