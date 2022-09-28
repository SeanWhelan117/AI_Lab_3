#include "NPCPursue.h"

NPCPursue::NPCPursue()
{
	loadFiles();
	pursueSprite.setPosition(2100, 700);
	pursueSprite.setTexture(pursueTexture);
	pursueSprite.setOrigin(pursueSprite.getGlobalBounds().width / 2, pursueSprite.getGlobalBounds().height / 2);
	pursueSprite.setScale(6, 6);
}

void NPCPursue::loadFiles()
{
	if (!pursueTexture.loadFromFile("ASSETS\\IMAGES\\pursueNPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading pursueSprite (pursueNPC)" << std::endl;
	}
}

void NPCPursue::update(sf::Time t_deltaTime)
{
}

void NPCPursue::render(sf::RenderWindow& t_window)
{
	t_window.draw(pursueSprite);
}
