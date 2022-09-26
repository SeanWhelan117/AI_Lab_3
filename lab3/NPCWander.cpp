#include "NPCWander.h"

NPCWander::NPCWander()
{
	loadFiles();
	wanderSprite.setPosition(700, 700);
	wanderSprite.setTexture(wanderTexture);
	wanderSprite.setOrigin(wanderSprite.getGlobalBounds().width / 2, wanderSprite.getGlobalBounds().height / 2);
	wanderSprite.setScale(6, 6);
	wanderSetup();
}

void NPCWander::loadFiles()
{
	if (!wanderTexture.loadFromFile("ASSETS\\IMAGES\\wanderNPC.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading wanderSprite (wanderNPC)" << std::endl;
	}
}

void NPCWander::update(sf:: Time t_deltaTime)
{

}

void NPCWander::render(sf::RenderWindow& t_window)
{
	t_window.draw(wanderSprite);
}

void NPCWander::wanderSetup()
{
	//wanderOrientation += random(-1, +1) * wanderRate
	//	targetOrientation = wanderOrientation + my.orientation
	//	// Get the centre of the wander circle
	//	target = my.position + wanderOffset * my.orientation.asVector()
	//	target += wanderRadius * targetOrientation.asVector()
	//	steering = face.getSteering(target)
	//	//Full acceleration in direction we are facing
	//	steering.linear = maxAcc * my.orientation.asVector()

	int randOrientation = rand() % 3 + 1;
	std::cout << randOrientation << std::endl;

	//int targetOrientation = randOrientation + wanderSprite.getOrientai
}
