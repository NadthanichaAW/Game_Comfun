#include "Monster.h"

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, float x, float y)
	:animation(texture, imageCount, switchTime)
{

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);
}

Monster::~Monster()
{
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
