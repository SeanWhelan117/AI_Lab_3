/// <summary>
/// author Pete Lowe May 2019
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "NPCWander.h"
#include "NPCArrive.h"
#include "NPCPursue.h"
#include "NPCSeek.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	Player m_player;
	NPCWander m_wander;
	NPCArrive m_arrive;
	NPCPursue m_pursue;
	NPCSeek m_seek;

	void boundaryCollisionCheck();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

	bool wanderActive = false;
	bool arriveActive = false;
	bool pursueActive = false;
	bool seekActive = false;


	sf::Font m_ArialBlackfont;
	sf::Text m_welcomeMessage;
};
#endif // !GAME_HPP

