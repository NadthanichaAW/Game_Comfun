#include "Item.h"
#include <iostream>

Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y)
: animation(texture,imageCount,switchTime)
{
	Cstar = 0;
	row = 0;
	body.setSize(sf::Vector2f(35.0f, 44.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Item::~Item()
{

}

void Item::update(float deltatime, Player player)
{
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

	if (player.GetCollision().CheckCollision(this->GetCollider()))
	{
		Cstar++;
		std::cout << "\t\t thisCollider";
		body.setPosition(-1000.0f, 350.0f); //ชนแล้วไปอยู่หลังฉาก 
	}
	
}

void Item::drawItem(sf::RenderWindow& window)
{
	window.draw(body);
}
