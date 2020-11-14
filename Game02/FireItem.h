#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collision.h"
#include <time.h>

class FireItem
{
public:
	FireItem(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
	~FireItem();

	void updateItemFire(float deltatime);
	void drawItemFire(sf::RenderWindow& window);


	Collision GetCollider() { return Collision(body); }
private:
	int row;
	sf::RectangleShape body;
	Animation animation;
};

