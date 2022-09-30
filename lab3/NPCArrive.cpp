#include "NPCArrive.h"

NPCArrive::NPCArrive()
{
	loadFiles();
	arriveSprite.setPosition(2400, 700);
	arriveSprite.setTexture(arriveTexture);
	arriveSprite.setOrigin(arriveSprite.getGlobalBounds().width / 2, arriveSprite.getGlobalBounds().height / 2);
	arriveSprite.setScale(6, 6);
}

void NPCArrive::loadFiles()
{
	if (!arriveTexture.loadFromFile("ASSETS\\IMAGES\\arriveNPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading arriveSprite (arriveNPC)" << std::endl;
	}
}

void NPCArrive::update(Player &t_player, sf::Time t_deltaTime)
{
	arriving(t_player, t_deltaTime);
}

void NPCArrive::render(sf::RenderWindow& t_window)
{
	t_window.draw(arriveSprite);
}

void NPCArrive::arriving(Player& t_player, sf::Time t_deltaTime)
{
	//desired_velocity = normalize(position - target) * max_speed

	sf::Vector2f playerPosition = t_player.playerSprite.getPosition();
	sf::Vector2f seekerPosition = arriveSprite.getPosition();


	float angleX = seekerPosition.x - playerPosition.x;
	float angleY = seekerPosition.y - playerPosition.y;

	float rotation = (-atan2(angleX, angleY)) * 180 / PI;
	arriveSprite.setRotation(rotation);


	velocity = playerPosition - seekerPosition;
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
		speed = 8;
	}

	arriveSprite.move(velocity);
}
