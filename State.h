#ifndef STATE_H
#define STATE_H

#include "PlayerCharacter.h"
class State
{
private:

protected:

	std::stack<State*>* states;
	sf::RenderWindow* window;
	//mapy - obs³uga klawiszy
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Zasoby
	std::map<std::string, sf::Texture> textures;

	//Funkcje
	virtual void OpenKeybinds() = 0;

public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	void endState();

	virtual void updateMousePosition();
	virtual void updateInput(const float& time) =0;
	virtual void update(const float& time) = 0;
	virtual void render(sf::RenderTarget* target =NULL) = 0;
};

#endif

