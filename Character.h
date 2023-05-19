#pragma once

#include "MovementComponent.h"
#include "AnimationComponent.h"
class Character
{
private:
	void OpenVariables();
protected:
	//sf::Texture * texture; //Robimy wskaünik, poniewaø ≥adowanie orginalnych tekstur to jakiú absurd!!!!
	sf::Sprite sprite;

	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	/*sf::RectangleShape shape;
	float speed;*/
public:
	Character();
	virtual ~Character();

	//wyúwietlanie i ruch postaci
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxSpeed, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);

	//Metody
	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float& time);

	virtual void update(const float& time);
	virtual void render(sf::RenderTarget* target);

};

