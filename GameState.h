#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
class GameState : public State
{
private:
	PlayerCharacter* player;

	//Funkcje
	void OpenKeybinds();
	void OpenTextures();
	void OpenPlayers();
public:

	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();
	//Funkcje Stanów Gry
	void updateInput(const float& time);
	void update(const float& time);
	void render(sf::RenderTarget* target=NULL);
};
#endif 
