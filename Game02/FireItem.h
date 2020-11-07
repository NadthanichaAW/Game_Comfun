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
	/*int iscollider()
	{
		if (hit == 1)
		{
			hit--;
			return 1;
		}
	}*/

	Collision GetCollider() { return Collision(body); }
private:
	int hit;
	int row;
	sf::RectangleShape body;
	Animation animation;
};

