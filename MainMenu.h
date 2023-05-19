#pragma once

#include "GameState.h"
#include"Button.h"

class MainMenu : public State
{
private:
	//zmienne
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*>buttons;
	//Funkcje
	void OpenVariables();
	void OpenBackground();
	void OpenFonts();
	void OpenKeybinds();
	void OpenButtons();
public:
	MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenu();

	//Funkcje Stanów Gry
	void updateInput(const float& time);
	void updateButtons();
	void update(const float& time);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);

};

