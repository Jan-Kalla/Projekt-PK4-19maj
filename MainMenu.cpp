#include "MainMenu.h"

//Funkcje inicjalizuj¹ce
void MainMenu::OpenVariables()
{

}

void MainMenu::OpenBackground()
{
	this->background.setSize(sf::Vector2f(
		static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)));

	if(!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/Purple_Fantasy.jpg"))
	{
		//throw("ERROR::MainMenu::Ladowanie_Tekstury_Tla");
	}
	
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenu::OpenFonts()
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales.ttf"))
	{
		//throw("ERROR::MainMenu::Odczyt czcionki");
	}

}

void MainMenu::OpenKeybinds()
{
	std::ifstream ifs("Config/MainMenu_keys.txt");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();
}

void MainMenu::OpenButtons()
{
	this->buttons["GameState"] = new Button(75, 50, 200, 75,
		&this->font, "New Game",
		sf::Color(200, 50, 250, 255), sf::Color(255, 150, 255, 255), sf::Color(0, 0, 0, 255),
		sf::Color(20, 20, 20, 0), sf::Color(150, 150, 150, 0), sf::Color(0, 0, 200, 0));

	this->buttons["Settings"] = new Button(75, 150, 200, 75,
		&this->font, "Settings",
		sf::Color(200, 50, 250, 255), sf::Color(255, 150, 255, 255), sf::Color(255, 0, 50, 255),
		sf::Color(20, 20, 20, 0), sf::Color(150, 150, 150, 0), sf::Color(0, 0, 0, 0));

	this->buttons["EditorState"] = new Button(75, 250, 200, 75,
		&this->font, "Editor",
		sf::Color(200, 50, 250, 255), sf::Color(255, 150, 255, 255), sf::Color(255, 0, 50, 255),
		sf::Color(20, 20, 20, 0), sf::Color(150, 150, 150, 0), sf::Color(0, 0, 0, 0));

	this->buttons["ExitState"] = new Button(75, 350, 200, 75,
		&this->font, "Exit",
		sf::Color(200, 50, 250, 255), sf::Color(255, 150, 255, 255), sf::Color(0, 0, 0, 255),
		sf::Color(20, 20, 20, 0), sf::Color(150, 150, 150, 0), sf::Color(0, 0, 200, 0));
}

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->OpenVariables();
	this->OpenBackground();
	this->OpenFonts();
	this->OpenKeybinds();
	this->OpenButtons();

	/**/

	/*this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);*/
}

MainMenu::~MainMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); it++)
	{
		delete it->second;
	}
}

void MainMenu::updateInput(const float& time)
{
	//wyjœcie z gry

	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))


}

void MainMenu::updateButtons()
{
	for (auto & it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//wyjœcie z gry
	if (this->buttons["ExitState"]->isPressed())
	{
		this->endState();
	}

	//nowa gra
	if (this->buttons["GameState"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this ->states));
	}
}

void MainMenu::update(const float& time)
{
	this->updateMousePosition();
	this->updateInput(time);

	this->updateButtons();

	//
	/*system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;*/
}

void MainMenu::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

}

void MainMenu::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
	//Kod poni¿ej raczej tylko do trybu debugowania
	/*sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(25);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}