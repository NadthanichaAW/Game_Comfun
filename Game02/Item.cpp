#include "Item.h"
#include <iostream>
#include <math.h>

Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y)
: animation(texture,imageCount,switchTime)
{
	this->checkHit = false;
	this->checkDia = false;
	this->nubTime = 0;
	this->twoTime = 0;
	Pclock = 0;
	Pcoin = 0;
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Item::~Item()
{

}

void Item::updateItem(float deltatime, Player player)
{
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

	if (player.GetCollision().CheckCollision(this->GetCollider()))
	{
		Pclock += 1;
		Pcoin += 1;
		std::cout << "\t\t thisCollider";
		body.setPosition(-1000.0f, 350.0f); //chon laew pai yhu back bg 

	}	
}

void Item::drawItem(sf::RenderWindow& window)
{
	window.draw(body);
}

void Item::chestHit(float deltatime, Player player)
{
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);
	if ((abs(player.GetPosition().x - body.getPosition().x)<= 50 && abs(player.GetPosition().y - body.getPosition().y) <= 50)&& sf::Mouse::isButtonPressed(sf::Mouse::Left))//check position abs <- check two way left and right
	{
		this->checkHit = true;
	}
	if (this->checkHit==true)
	{
		
		nubTime += deltatime;
		if (nubTime >= 4)
		{
			nubTime = 0;
			row = 1;
		}
		if (row==1)
		{
			twoTime += deltatime;
			if (twoTime >= 1)
			{
				twoTime = 0;
				body.setPosition(-1000.0f, 500.0f);
				this->checkHit = false;//pic lost
				if (this->checkHit == false)
				{
					this->checkDia = true;
				}
			}
		}
	}

}

void Item::updateDiamond(float deltatime, Player player)
{
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

	if (player.GetCollision().CheckCollision(this->GetCollider()))
	{
		body.setPosition(-1500.0f, 500.0f); //chon laew pai yhu back bg 
	}
}
