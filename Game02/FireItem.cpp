#include "FireItem.h"
#include <iostream>

FireItem::FireItem(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y)
:animation(texture, imageCount, switchTime)
{
	row = 0;
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

FireItem::~FireItem()
{
}

void FireItem::updateItemFire(float deltatime)
{
	animation.updateFire(row, deltatime);
	body.setTextureRect(animation.uvRect);
}

void FireItem::drawItemFire(sf::RenderWindow& window)
{
	window.draw(body);
}
