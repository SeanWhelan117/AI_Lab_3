/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ sf::VideoMode::getDesktopMode().width , sf::VideoMode::getDesktopMode().height , 32U }, "SFML Game" },
	m_exitGame{ false } //when true game will exit
{
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	//if (sf::Keyboard::Escape == t_event.key.code)
	//{
	//	m_exitGame = true;
	//}

	switch (t_event.key.code)
	{
	case sf::Keyboard::Escape:
		m_exitGame = true;
		break;

	case sf::Keyboard::Num1:
		if (wanderActive == false)
		{
			wanderActive = true;
		}
		else if (wanderActive == true)
		{
			wanderActive = false;
		}
		break;

	case sf::Keyboard::Num2:
		if (arriveActive == false)
		{
			arriveActive = true;
		}
		else if (arriveActive == true)
		{
			arriveActive = false;
		}
		break;

	case sf::Keyboard::Num3:
		if (seekActive == false)
		{
			seekActive = true;
		}
		else if (seekActive == true)
		{
			seekActive = false;
		}
		break;

	case sf::Keyboard::Num4:
		if (pursueActive == false)
		{
			pursueActive = true;
		}
		else if (pursueActive == true)
		{
			pursueActive = false;
		}
		break;
	default:
		break;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	m_player.update(t_deltaTime);
	if (wanderActive == true)
	{
		m_wander.update(t_deltaTime);
	}
	if (arriveActive == true)
	{
		m_arrive.update(m_player, t_deltaTime);
	}
	if (seekActive == true)
	{
		m_seek.update(t_deltaTime, m_player);
	}
	if (pursueActive == true)
	{
		m_pursue.update(t_deltaTime);
	}


	boundaryCollisionCheck();

	if (m_exitGame)
	{
		m_window.close();
	}

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	m_player.render(m_window);

	if (wanderActive == true)
	{
		m_wander.render(m_window);
	}

	if (arriveActive == true)
	{
		m_arrive.render(m_window);
	}
	if (seekActive == true)
	{
		m_seek.render(m_window);
	}
	if (pursueActive == true)
	{
		m_pursue.render(m_window);
	}

	m_window.display();
}

///// <summary>
///// load the font and setup the text message for screen
///// </summary>
//void Game::setupFontAndText()
//{
//	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
//	{
//		std::cout << "problem loading arial black font" << std::endl;
//	}
//	m_welcomeMessage.setFont(m_ArialBlackfont);
//	m_welcomeMessage.setString("SFML Game");
//	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
//	m_welcomeMessage.setPosition(40.0f, 40.0f);
//	m_welcomeMessage.setCharacterSize(80U);
//	m_welcomeMessage.setOutlineColor(sf::Color::Red);
//	m_welcomeMessage.setFillColor(sf::Color::Black);
//	m_welcomeMessage.setOutlineThickness(3.0f);
//
//}

void Game::boundaryCollisionCheck()
{
	sf::Vector2f playerPos = m_player.playerSprite.getPosition();

	if (playerPos.x > sf::VideoMode::getDesktopMode().width)
	{
		m_player.playerSprite.setPosition(0 - m_player.playerOffset, m_player.playerSprite.getPosition().y);
	}
	if (playerPos.x < 0 - m_player.playerOffset)
	{
		m_player.playerSprite.setPosition(sf::VideoMode::getDesktopMode().width, m_player.playerSprite.getPosition().y);
	}
	
	if (playerPos.y > sf::VideoMode::getDesktopMode().height)
	{
		m_player.playerSprite.setPosition(m_player.playerSprite.getPosition().x, 0 - m_player.playerOffset);
	}
	if (playerPos.y < 0 - m_player.playerOffset)
	{
		m_player.playerSprite.setPosition(m_player.playerSprite.getPosition().x, sf::VideoMode::getDesktopMode().height);
	}


	sf::Vector2f wanderPos = m_wander.wanderSprite.getPosition();

	if (wanderPos.x > sf::VideoMode::getDesktopMode().width)
	{
		m_wander.wanderSprite.setPosition(0 - m_wander.wanderOffset, m_wander.wanderSprite.getPosition().y);
	}
	if (wanderPos.x < 0 - m_wander.wanderOffset)
	{
		m_wander.wanderSprite.setPosition(sf::VideoMode::getDesktopMode().width, m_wander.wanderSprite.getPosition().y);
	}

	if (wanderPos.y > sf::VideoMode::getDesktopMode().height)
	{
		m_wander.wanderSprite.setPosition(m_wander.wanderSprite.getPosition().x, 0 - m_wander.wanderOffset);
	}
	if (wanderPos.y < 0 - m_wander.wanderOffset)
	{
		m_wander.wanderSprite.setPosition(m_wander.wanderSprite.getPosition().x, sf::VideoMode::getDesktopMode().height);
	}

}

