#ifndef GAME_H
#define GAME_H


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "MainMenu.h"

class Game
{
private:
	//zmienne
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;

	sf::ContextSettings windowSettings;
	bool fullscreen;

	sf::Clock timeClock;
	float time;
	std::stack < State* > states;

		std::map<std::string, int> supportedKeys;
	//funkcje inicjalizuj¹ce
	void OpenVariables();
	void OpenWindow();
	void OpenKeys();
	void OpenStates();
public:
	Game();
	virtual ~Game();
	//Funkcje

	//Regulacje
	void endApp();

	//silnik gry
	void updateTime();
	void updateSFML();
	void update();

	//wyœwietlanie
	void render();
	void run();
};

#endif