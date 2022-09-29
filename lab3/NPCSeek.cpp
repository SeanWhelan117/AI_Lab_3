#include "NPCSeek.h"

NPCSeek::NPCSeek()
{
	loadFiles();
	seekSprite.setPosition(1800, 700);
	seekSprite.setTexture(seekTexture);
	seekSprite.setOrigin(seekSprite.getGlobalBounds().width / 2, seekSprite.getGlobalBounds().height / 2);
	seekSprite.setScale(6, 6);
}

void NPCSeek::loadFiles()
{
	if (!seekTexture.loadFromFile("ASSETS\\IMAGES\\seekNPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading seekSprite (seekNPC)" << std::endl;
	}
}

void NPCSeek::update(sf::Time t_deltaTime, Player& t_player)
{
	seeking(t_player, t_deltaTime);
}

void NPCSeek::render(sf::RenderWindow& t_window)
{
	t_window.draw(seekSprite);
}

void NPCSeek::seeking(Player &t_player, sf::Time t_deltaTime)
{
	//desired_velocity = normalize(position - target) * max_speed

	sf::Vector2f playerPosition = t_player.playerSprite.getPosition();
	sf::Vector2f seekerPosition = seekSprite.getPosition();
	

	float angleX = seekerPosition.x - playerPosition.x;
	float angleY = seekerPosition.y - playerPosition.y;

	float rotation = (-atan2(angleX, angleY)) * 180 / PI;
	seekSprite.setRotation(rotation);
	

	velocity = playerPosition - seekerPosition; 
	float squareRootVelocity = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
	velocity = sf::Vector2f{ velocity.x / squareRootVelocity , velocity.y / squareRootVelocity };
	velocity = velocity * speed;
	
	seekSprite.move(velocity);
	
}
