#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxSpeed, float acceleration, float deceleration)
	: sprite(sprite),
	maxSpeed(maxSpeed), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

const sf::Vector2f& MovementComponent::getSpeed() const
{
	// TODO: tu wstawiæ instrukcjê return
	return this->speed;
}

//metody
void MovementComponent::move(const float x, const float y, const float& time)
{
	/* Przyspieszanie postaci do momentu osi¹gniêcia max prêdkoœci */

	this->speed.x += this->acceleration * x;
	this->speed.y += this->acceleration * y;
}

//Do tej pory najbardziej irytuj¹ca metoda w programie, kosztowa³a mnie wiele nerwów, a daje wsm niewiele...
void MovementComponent::update(const float& time)
{
	/*
	spowalnianie postaci i kontrola max prêdkoœci dla ka¿dego kierunku
	*/

	if (this->speed.x > 0.f) //sprawdzanie dla dodatniego x
	{
		// kontrola max prêdkoœci
		if (this->speed.x > this->maxSpeed)
			this->speed.x = this->maxSpeed;

		//spowalnianie postaci
		this->speed.x -= deceleration;
		if (this->speed.x < 0.f)
			this->speed.x = 0.f;
	}
	else if (this->speed.x < 0.f) //sprawdzanie dla ujemnego x
	{
		// kontrola max prêdkoœci
		if (this->speed.x < -this->maxSpeed)
			this->speed.x = -this->maxSpeed;

		//spowalnianie postaci
		this->speed.x += deceleration;
		if (this->speed.x > 0.f)
			this->speed.x = 0.f;
	}

	if (this->speed.y > 0.f) //sprawdzanie dla dodatniego y
	{
		// kontrola max prêdkoœci
		if (this->speed.y > this->maxSpeed)
			this->speed.y = this->maxSpeed;

		//spowalnianie postaci
		this->speed.y -= deceleration ;
		if (this->speed.y < 0.f)
			this->speed.y = 0.f;
	}
	else if (this->speed.y < 0.f) //sprawdzanie dla ujemnego y
	{
		// kontrola max prêdkoœci
		if (this->speed.y < -this->maxSpeed)
			this->speed.y = -this->maxSpeed;

		//spowalnianie postaci
		this->speed.y += deceleration;
		if (this->speed.y > 0.f)
			this->speed.y = 0.f;
	}

	//ostateczny ruch
	this->sprite.move(this->speed * time); //u¿ywa prêdkoœæ
}

//Ca³a ta metoda to by³o dla mnie na prawdê ogromne poœwiêcenie, mam nadziejê, ¿e by³o warto ;)
