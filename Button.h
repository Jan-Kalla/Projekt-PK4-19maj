#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>


#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

enum buttoStates {BTN_IDLE = 0,  BTN_HOVER, BTN_ACTIVE };
class Button
{
private:
	short unsigned buttonState;
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color text_idleColor; //NIEnajechany PRZYCISK - kolor czcionki
	sf::Color text_hoverColor; //Najechany PRZYCISK - kolor czcionki
	sf::Color text_activeColor; //WCIŒNIÊTY PRZYCISK - kolor czcionki

	sf::Color idleColor; //NIEnajechany PRZYCISK
	sf::Color hoverColor; //Najechany PRZYCISK
	sf::Color activeColor; //WCIŒNIÊTY PRZYCISK

public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color text_idleColor, sf::Color text_hoverColor, sf::Color text_activeColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	//kontrola "wciœniêcia"
	const bool isPressed() const;

	//Funkcje
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};

