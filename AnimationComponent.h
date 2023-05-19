#pragma once

#include <iostream>
#include <string>
#include <map>

#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class AnimationComponent //Pocz¹tkowo mia³a siê tutaj znajdowaæ jedynie klasa AnimationComponent, ale jak zwykle nie da³o siê tak prosto
{
private:
	class Animation
	{
	public:
		//zmienne
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animeTimer;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		//Tutaj deklarowane s¹ wszystkie parametry potrzebne do animacji
		Animation(sf::Sprite& sprite, sf::Texture& texture_sheet,
			float anime_timer,
			int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
			: sprite(sprite), textureSheet(texture_sheet), animeTimer(anime_timer), width(width), height(height)
		{
			this->timer = 0.f;
			this->startRect = sf::IntRect(start_frame_x*width, start_frame_y*height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frames_x*width, frames_y*height, width, height);
			//this->startRect == this->endRect;

			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}


		
		//Metody
		void play(const float& time)
		{
			this->timer += 100.f * time;
			if (this->timer >= this->animeTimer)
			{
				//reset zegara
				this->timer = 0.f;
				//Animacja
				if (this->currentRect != this->endRect)
				{
					this->currentRect.left += this->width;
				}
				else //Reset
				{
					this->currentRect.left = this->startRect.left;
				}
				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset()
		{
			this->timer = 0.f;
			this->currentRect = this->startRect;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	std::map<std::string, Animation*> animations;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	~AnimationComponent();

	//Metody
	void addAnimation(const std::string key,
		float anime_timer, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);

	/*void startAnimation(const std::string animation);
	void pauseAnimation(const std::string animation);
	void resetAnimation(const std::string animation);*/


	void play(const std::string key, const float& time);
};

