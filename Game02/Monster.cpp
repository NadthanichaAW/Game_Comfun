#include "Monster.h"

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y)
	:animation(texture, imageCount, switchTime)
{
	row = 0;
	this->face = 1; //check move
	this->posX = x;
	this->posY = y;
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
	velocity.x = 40;
	velocity.y = 0;
	if (positionX < this->posX)//thar pos mons < pos start hai mons move right 
	{
		
		this->face = 1;
	}
	else if (positionX > this->posX + 250)
	{
		
		this->face = -1;
	}
	body.move(this->face * velocity * deltatime);
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

}

void Monster::updateXslim(float deltatime)
{
	float positionX = body.getPosition().x;
	velocity.x = 50;
	velocity.y = 0;
	if (positionX > this->posX + 250)
	{
		row = 1;
		this->face = -1;
		
	}
	else if (positionX < this->posX)
	{
			row = 0;
			this->face = 1;
	}
	body.move(this->face * velocity * deltatime);
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);
}


void Monster::updateXMons(float deltatime)
{
	float positionX = body.getPosition().x;
	velocity.x = 40;
	velocity.y = 0;
	if (positionX < this->posX)//thar pos mons < pos start hai mons move right 
	{
		row = 0;
		this->face = 1;
	}
	else if (positionX > this->posX + 250)
	{
		row = 1;
		this->face = -1;
	}
	body.move(this->face * velocity * deltatime);
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);
}


void Monster::updateEnermy(float deltatime)
{
	float positionY = body.getPosition().y;
	velocity.x = 0;
	velocity.y = 40;
	if (positionY < this->posY)//thar pos mons < pos start hai mons move down
	{
		row = 0;
		this->face = 1;
	}
	else if (positionY > this->posY + 250)
	{
		row = 1;
		this->face = -1;
	}
	body.move(this->face * velocity * deltatime);
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);
}

void Monster::drawMonster(sf::RenderWindow& window)
{
	window.draw(body);
}
