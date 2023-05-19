#include "PlayerCharacter.h"

//Funkcje inicjalizuj¹ce
void PlayerCharacter::OpenVariables()
{

}

void PlayerCharacter::OpenComponents()
{

}

PlayerCharacter::PlayerCharacter(float x, float y, sf::Texture& texture_sheet)
{
	this->OpenVariables();

	this->setPosition(x, y);

	this->createMovementComponent(300.f, 15.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("Man_idle", 20.f, 0, 0, 3, 0, 48, 48);
}

PlayerCharacter::~PlayerCharacter()
{

}

//Metody
void PlayerCharacter::update(const float& time)
{
	this->movementComponent->update(time);

	this->animationComponent->play("Man_idle", time);
}


