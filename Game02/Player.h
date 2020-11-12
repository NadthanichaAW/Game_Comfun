#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include "Collision.h"
#include "Hitbox.h"
#include "Monster.h"

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
	void updateMonster(float deltatime,std::vector<Monster>& monsterFVector);
	void updateSlimP(float deltatime, std::vector<Monster>& slimPvector);
	void updateMonS(float deltatime, std::vector<Monster>& monsterVector);
	void updateEnermies(float deltatime, std::vector<Monster>& enermyVector);

private:
	int hMons;
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed  ;
	int faceDirection;
	bool attack;
	int hitbox;
	int r;
	
};

