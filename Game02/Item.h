#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Animation.h"
#include"Collision.h"



class Item
{
public:
	Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y);//2 back position 
	~Item();
	void updateItem(float deltatime, Player player);
	void drawItem(sf::RenderWindow& window);
	int pointCoins(){
		if (Pcoin == 1)
		{
			Pcoin--;
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
	int pointDiamond()
	{
		if (Pdia == 1)
		{
			Pdia--;
			return 1;
		}
	}
	void chestHit(float deltatime, Player player);
	bool drawDia() { return this->checkDia; }
	void updateDiamond(float deltatime, Player player);
	Collision GetCollider() { return Collision(body); }


private:
	bool checkHit;
	bool checkDia;
	float nubTime;
	float twoTime;
	int Pdia;
	int Pclock;
	int Pcoin;
	int row;
	sf::RectangleShape body;
	Animation animation;

};

