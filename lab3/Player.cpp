#include "Player.h"


Player::Player()
{
	loadFiles();
	playerSprite.setPosition(200, 200);
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	//pursueSprite.setScale(6, 6);
	playerSprite.setScale(2, 2);
	setupPlayerCircle();
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
	movePlayer(t_deltaTime);
	playerCircle.setPosition(playerSprite.getPosition());
	getHeadingPoint();


	

}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(playerCircle);
	t_window.draw(playerSprite);
	sf::VertexArray lines(sf::LinesStrip, 2);
	lines[0].position = playerCircle.getPosition();
	lines[1].position = sf::Vector2f(playerCircle.getPosition().x + getHeadingPoint().x, playerCircle.getPosition().y - getHeadingPoint().y);
	t_window.draw(lines);

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
		if (speed < maxSpeed)
		{
			speed++;
		}
		else
		{
			speed = maxSpeed;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (speed > -15)
		{
			speed--;
		}
		else
		{
			speed = -15;
		}
	}
}


void Player::rotatePlayer(int t_rotation)
{
	playerSprite.rotate(t_rotation);
}

void Player::movePlayer(sf::Time t_deltaTime)
{
	velocityX = speed * sin(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
	velocityY = speed * -cos(playerSprite.getRotation() * t_deltaTime.asMilliseconds() / 1000);
	playerSprite.move(velocityX, velocityY);
}

void Player::setupPlayerCircle()
{
	playerCircle.setRadius(playerCircleRadius);
	playerCircle.setOrigin(playerCircleRadius, playerCircleRadius);
	playerCircle.setFillColor(sf::Color(0,255,0,100));
}

sf::Vector2f Player::getHeadingPoint()
{
	// (x,y) =(r*sin(angle, r*cos(angle)

	float headingX = playerCircleRadius * sin(playerSprite.getRotation());
	float headingY = playerCircleRadius * cos(playerSprite.getRotation());
	std::cout << headingX << "  ----  " << headingY << std::endl;
	sf::Vector2f headingPoint(headingX, headingY);

	return headingPoint;
}


