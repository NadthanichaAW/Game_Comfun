#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Animation.h"
#include"Collision.h"
class Monster
{
public:
	Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y);
	~Monster();

	void updateX(float deltatime);
	void updateMonster(float deltatime, Player player);
	void drawMonster(sf::RenderWindow& window);

	Collision GetCollider() { return Collision(body); }

private:	
	float face;
	float posX, posY;
	int row;
	sf::Vector2f velocity;
	sf::RectangleShape body;
	Animation animation;
	
};

