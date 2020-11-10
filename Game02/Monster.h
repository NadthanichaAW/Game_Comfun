#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Animation.h"
#include"Collision.h"
class Monster
{
public:
	Monster(sf::Texture* texture, sf::Vector2u imageCount,float w,float h, float switchTime, float x, float y);
	~Monster();

private:
	
	
	sf::RectangleShape body;
	Animation animation;

};

