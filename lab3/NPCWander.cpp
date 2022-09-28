#include "NPCWander.h"

NPCWander::NPCWander()
{
	loadFiles();
	wanderSprite.setPosition(1500, 700);
	wanderSprite.setTexture(wanderTexture);
	wanderSprite.setOrigin(wanderSprite.getGlobalBounds().width / 2, wanderSprite.getGlobalBounds().height / 2);
	wanderSprite.setScale(6, 6);
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
	wandering(t_deltaTime);
}

void NPCWander::render(sf::RenderWindow& t_window)
{
	t_window.draw(wanderSprite);
}

void NPCWander::wandering(sf::Time t_deltaTime)
{
	//wanderOrientation += random(-1, +1) * wanderRate
	//	targetOrientation = wanderOrientation + my.orientation
	//	// Get the centre of the wander circle
	//	target = my.position + wanderOffset * my.orientation.asVector()
	//	target += wanderRadius * targetOrientation.asVector()
	//	steering = face.getSteering(target)
	//	//Full acceleration in direction we are facing
	//	steering.linear = maxAcc * my.orientation.asVector()

	int randOrientation = rand() % 20 - 10;


	std::cout << randOrientation << std::endl;

	angle = wanderSprite.getRotation();
	angle = angle + randOrientation;
	
	float forwardx = speed * sin(angle * t_deltaTime.asMilliseconds() / 1000);
	float forwardy = speed * -cos(angle * t_deltaTime.asMilliseconds() / 1000);

	//float forwardx = speed * sin(angle * t_deltaTime.asSeconds());
	//float forwardy = speed * -cos(angle * t_deltaTime.asSeconds());


	float squareRootForward = sqrt((forwardx * forwardx) + (forwardy * forwardy));
	
	
	sf::Vector2f forwardVelocity(forwardx, forwardy);
	sf::Vector2f normalisedVelocity = forwardVelocity / squareRootForward;
	
	
	
	wanderSprite.move(normalisedVelocity);
	wanderSprite.setRotation(angle);
}
