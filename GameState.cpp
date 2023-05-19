#include "GameState.h"

//Funkcje inicjalizuj¹ce
void GameState::OpenKeybinds()
{
	std::ifstream ifs("Config/GameState_keys.txt");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys -> at(key2);
		}
	}
	ifs.close();
}

void GameState::OpenTextures()
{
	if (this->textures["PLAYERCHARACTER_SHEET"].loadFromFile("Resources/Images/PlayerCharacter/Man_idle.png"))
	{
		//throw ("ERROR::Game_State::wczytywanie_tekstur_postaci");
	}
}

void GameState::OpenPlayers()
{
	this->player = new PlayerCharacter(0, 0, this->textures["PLAYERCHARACTER_SHEET"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window,supportedKeys, states)
{
	this->OpenKeybinds();
	this->OpenTextures();
	this->OpenPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::updateInput(const float& time)
{
	//wyjœcie z gry
	
	//ruch postaci
	if (this->keybinds.count("Move_Up") > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Up")))) {
			this->player->move( 0.f, -1.f,time);
		}
	}
	if (this->keybinds.count("Move_Down") > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Down")))) {
			this->player->move( 0.f, 1.f, time);
		}
	}
	if (this->keybinds.count("Move_Left") > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Left")))) {
			this->player->move( -1.f, 0.f, time);
		}
	}
	if (this->keybinds.count("Move_Right") > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Move_Right")))) {
			this->player->move( 1.f, 0.f, time);
		}
	}
	if (this->keybinds.count("Close") > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Close")))) {
			this->endState();
		}
	
	}
}

void GameState::update(const float& time)
{
	this->updateMousePosition();
	this->updateInput(time);

	this->player->update(time);

}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
		this->player->render(target);
}

