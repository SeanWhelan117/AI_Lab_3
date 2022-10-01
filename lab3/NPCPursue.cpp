#include "NPCPursue.h"

NPCPursue::NPCPursue()
{
	loadFiles();
	pursueSprite.setPosition(1200, 700);
	pursueSprite.setTexture(pursueTexture);
	pursueSprite.setOrigin(pursueSprite.getGlobalBounds().width / 2, pursueSprite.getGlobalBounds().height / 2);
	//pursueSprite.setScale(6, 6);
	pursueSprite.setScale(2, 2);
}

void NPCPursue::loadFiles()
{
	if (!pursueTexture.loadFromFile("ASSETS\\IMAGES\\pursueNPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading pursueSprite (pursueNPC)" << std::endl;
	}
}

void NPCPursue::update(sf::Time t_deltaTime, Player& t_player)
{
	pursuing(t_player);
}

void NPCPursue::render(sf::RenderWindow& t_window)
{
	t_window.draw(pursueSprite);
}

void NPCPursue::pursuing(Player &t_player)
{
	sf::Vector2f playerPosition = t_player.playerSprite.getPosition();
	sf::Vector2f seekerPosition = pursueSprite.getPosition();
	sf::Vector2f playerHeadingPosition = t_player.getHeadingPoint();


	float angleX = seekerPosition.x - playerHeadingPosition.x;
	float angleY = seekerPosition.y - playerHeadingPosition.y;

	float rotation = (-atan2(angleX, angleY)) * 180 / PI;
	pursueSprite.setRotation(rotation);


	velocity = playerHeadingPosition - seekerPosition;
	float squareRootVelocity = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	velocity = sf::Vector2f{ velocity.x / squareRootVelocity , velocity.y / squareRootVelocity };
	velocity = velocity * speed;

	if (squareRootVelocity < 20)
	{
		speed = 0;
	}
	else if (squareRootVelocity < 200)
	{
		speed = lowerSpeed;
	}
	else
	{
		speed = ogSpeed;
	}

	pursueSprite.move(velocity);
}
