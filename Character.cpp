#include "Character.h"

void Character::OpenVariables()
{
	this->movementComponent = NULL;
}

Character::Character()
{
	this->OpenVariables();
}

Character::~Character()
{
	delete this->movementComponent;
	delete this->animationComponent;
}
//wyœwietlanie
void Character::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Character::createMovementComponent(const float maxSpeed, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxSpeed, acceleration, deceleration);
}

void Character::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

//Metody

void Character::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x, y);
}


void Character::move(const float x, const float y, const float& time)
{
	//metoda odpowiedzialna za ruch, przy tej metodzie by³o sporo zamieszania,
	//ostatecznie zdecydowa³em siê j¹ zrobiæ porz¹dnie i opiera siê ona na parametrach time araz movementComponent
	if (this->movementComponent)
	{
		this->movementComponent->move(x, y, time);//ustawia prêdkoœæ
	}

}

void Character::update(const float& time)
{
	if (this->movementComponent)
		this->movementComponent->update(time);
}

void Character::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}


