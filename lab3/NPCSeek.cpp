#include "NPCSeek.h"

NPCSeek::NPCSeek()
{
	loadFiles();
	seekSprite.setPosition(900, 700);
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

void NPCSeek::update(sf::Time t_deltaTime, sf::Vector2f t_playerPos)
{
	seeking(t_playerPos);
}

void NPCSeek::render(sf::RenderWindow& t_window)
{
	t_window.draw(seekSprite);
}

void NPCSeek::seeking(sf::Vector2f t_playerPos)
{
	//desired_velocity = normalize(position - target) * max_speed
		//steering = desired_velocity - velocity
}
