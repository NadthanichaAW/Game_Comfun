#include "FireItem.h"
#include <iostream>

FireItem::FireItem(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y)
:animation(texture, imageCount, switchTime)
{
	row = 0;
	body.setSize(sf::Vector2f(80.0f, 192.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

FireItem::~FireItem()
{
}

void FireItem::updateItemFire(float deltatime, Player player)
{
	animation.updateItem(row, deltatime);
	body.setTextureRect(animation.uvRect);

	/*if (player.GetCollision().CheckCollision(this->GetCollider()))
	{
		std::cout << "\t\t thisCollider";
		//player.SetPosition(140.0f, 100.0f); //�������������ѧ�ҡ 
	}*/
}

void FireItem::drawItemFire(sf::RenderWindow& window)
{
	window.draw(body);
}
