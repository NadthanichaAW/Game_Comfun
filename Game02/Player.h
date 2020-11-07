#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include "Collision.h"
#include "Hitbox.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	~Player();
	
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(float x, float y);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollision() { return Collision(body); }


private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed  ;
	int faceDirection;
	bool attack;
	int hitbox;
	int r;
	
};

