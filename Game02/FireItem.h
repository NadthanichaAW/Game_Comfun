#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Animation.h"
#include"Collision.h"


class FireItem
{
public:
	FireItem(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
	~FireItem();

	void updateItemFire(float deltatime, Player player);
	void drawItemFire(sf::RenderWindow& window);
	

	Collision GetCollider() { return Collision(body); }
private:
	int row;
	sf::RectangleShape body;
	Animation animation;
};

