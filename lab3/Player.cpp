#include "Player.h"


Player::Player()
{
	loadFiles();
	playerSprite.setPosition(200, 200);
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(6, 6);
}

void Player::loadFiles()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\Player.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading playerSprite (player)" << std::endl;
	}
}


void Player::update()
{
	playerInput();
	movePlayer();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(playerSprite);
}



void Player::playerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotatePlayer(-5);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotatePlayer(5);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	}
}


void Player::rotatePlayer(int t_rotation)
{
	playerSprite.rotate(t_rotation);

}


void Player::movePlayer()
{

}

