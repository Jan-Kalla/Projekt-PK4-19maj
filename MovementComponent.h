#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<sstream>
#include<stack>
#include <map>


#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float maxSpeed;
	float acceleration;
	float deceleration;

	sf::Vector2f speed;

	//Initializer functions

public:
	MovementComponent(sf::Sprite& sprite,
		float maxSpeed, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accessors
	const sf::Vector2f& getSpeed() const;

	//Functions

	void move(const float x, const float y, const float& time);
	void update(const float& time);
};

