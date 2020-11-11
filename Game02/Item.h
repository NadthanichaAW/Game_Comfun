#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Animation.h"
#include"Collision.h"



class Item
{
public:
	Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);//2 back position 
	~Item();
	void updateItem(float deltatime, Player player);
	void drawItem(sf::RenderWindow& window);
	int pointCoins(){
		if (Pcoin == 10)
		{
			Pcoin-=10;
			return 1;
		}
	}
	int pointClocks()
	{
		if (Pclock == 1)
		{
			Pclock--;
			return 1;
		}
	}
	Collision GetCollider() { return Collision(body); }


private:
	int Pclock;
	int Pcoin;
	int row;
	sf::RectangleShape body;
	Animation animation;

};

