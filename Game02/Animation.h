#pragma once
#include<SFML/Graphics.hpp>
#include "Hitbox.h"
class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	~Animation();

	void Update(int row, float deltaTime);
	void updateItem(int row, float deltaTime);
	void updateFire(int row, float deltaTime);
	void updateMonters(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime ;
	float switchTime;
};

