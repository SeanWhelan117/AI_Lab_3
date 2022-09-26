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


void Player::update(sf::Time t_deltaTime)
{
	playerInput(t_deltaTime);
	movePlayer();
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(playerSprite);
}



void Player::playerInput(sf::Time t_deltaTime)
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
		float forwardx = speed * sin(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
		float forwardy = speed * -cos(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
		playerSprite.move(forwardx, forwardy);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		float backwardsX = speed * -sin(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
		float backwardsY = speed * cos(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
		playerSprite.move(backwardsX, backwardsY);
	}
}


void Player::rotatePlayer(int t_rotation)
{
	playerSprite.rotate(t_rotation);

}


void Player::movePlayer()
{

}

