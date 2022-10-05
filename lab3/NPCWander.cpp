#include "NPCWander.h"

NPCWander::NPCWander()
{
	loadFiles();
	wanderSprite.setPosition(1500, 700);
	wanderSprite.setTexture(wanderTexture);
	wanderSprite.setOrigin(wanderSprite.getGlobalBounds().width / 2, wanderSprite.getGlobalBounds().height / 2);
	wanderSprite.setScale(6, 6);
	setUpVisionCone();
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

	updateVisionCone();
}

void NPCWander::render(sf::RenderWindow& t_window)
{
	

	t_window.draw(wanderSprite);

	t_window.draw(lineLeft, 2, sf::Lines);


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

void NPCWander::setUpVisionCone()
{
	lineLeft[0].color = sf::Color::Green;
	lineLeft[1].color = sf::Color::White;
	lineRight[0].color = sf::Color::Red;
	lineRight[1].color = sf::Color::Red;
}

void NPCWander::updateVisionCone()
{

	visionConeLeftX = radiusVC * sin(angle);
	visionConeLeftY = radiusVC * -cos(angle);
	visionConeRightX = radiusVC * sin(angle);
	visionConeRightY = radiusVC * cos(angle);

	//std::cout << visionConeLeftX << "  ----  " << visionConeLeftY << std::endl;

	sf::Vector2f spritePos = wanderSprite.getPosition();


	lineLeft[0].position = spritePos;
	lineLeft[0].color = sf::Color::Green;
	lineLeft[1].position = sf::Vector2f(spritePos.x + 100, spritePos.y - 50);
	lineLeft[1].color = sf::Color::White;

	/*lineRight[0].position = sf::Vector2f(10, 0);
lineRight[0].color = sf::Color::Red;
lineRight[1].position = sf::Vector2f(20, 0);
lineRight[1].color = sf::Color::Red;*/

}
