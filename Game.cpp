#include "Game.h"
#include <iostream>

void Game::OpenVariables()
{
	this->window = NULL;
	this->fullscreen = false;
	this->time = 0.f;
}

//funkcje inicjalizuj¹ce
void Game::OpenWindow()
{
	//sf::ContextSettings::
	std::ifstream ifs("Config/window.txt");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	//window_bounds.bitsPerPixel
	bool fullscreen = false;
	unsigned framerate_limit = 75;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0; //wyg³adzanie krawêdzi

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}
	ifs.close();

	this->fullscreen = fullscreen;
	this-> windowSettings.antialiasingLevel = antialiasing_level;
	if (this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::OpenKeys()
{
	std::ifstream ifs("Config/supported_keys.txt");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}
	ifs.close();

	//Do usuniêcia!!!
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
}

void Game::OpenStates()
{
	this->states.push(new MainMenu(this->window, &this->supportedKeys, &this ->states));
	//this->states.push(new GameState(this->window, &this->supportedKeys));
}

Game::Game()
{
	this->OpenWindow();
	this->OpenKeys();
	this->OpenStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this -> states.pop();
	}
}
//Funkcje

void Game::endApp()
{
	std::cout << "Ending Application" << std::endl;
}

void Game::updateTime() // <- Uwaga, Uwaga, Najwa¿niesza metoda w programie!!!!!!!!
//Aktualizuje zmienn¹ time o czas wyrenderowania jednej klatki
{
	this->time = this->timeClock.restart().asSeconds();
		/*system("cls");
		std::cout << this->time << "\n";*/
}

void Game::updateSFML()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

	
}

void Game::update()
{
	this->updateSFML();
	if (!this->states.empty())
	{
		this->states.top()->update(this->time);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Wyjœcie z gry
	else
	{
		this->endApp();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
		this->states.top()->render(/*this->window*/);

	this->window->display();

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateTime();
		this->render();
		this->update();
	}

}
