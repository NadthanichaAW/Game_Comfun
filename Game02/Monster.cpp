#include "Monster.h"

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y)
	:animation(texture, imageCount, switchTime)
{
	this->face = 1; //check move
	this->posX = x;
	this->posY = y;
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(this->posX, this->posY);
	body.setTexture(texture);
}

Monster::~Monster()
{
}

void Monster::updateX(float deltatime)
{
	float positionX = body.getPosition().x;
	velocity.x = 50;
	velocity.y = 0;
	if (positionX < this->posX)//thar pos mons < pos start hai mons move right 
	{
		this->face = 1;
	}
	else if (positionX > this->posX + 200)
	{
		this->face = -1;
	}
	body.move(this->face * velocity * deltatime);
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

}

void Monster::updateMonster(float deltatime, Player player)
{
	
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);
}

void Monster::drawMonster(sf::RenderWindow& window)
{
	window.draw(body);
}
