#include "NPCArrive.h"

NPCArrive::NPCArrive()
{
	loadFiles();
	arriveSprite.setPosition(1300, 700);
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

void NPCArrive::update(sf::Time t_deltaTime)
{
}

void NPCArrive::render(sf::RenderWindow& t_window)
{
	t_window.draw(arriveSprite);
}
