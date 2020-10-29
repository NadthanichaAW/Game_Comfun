#ifndef HITBOX_H
#define HITBOX_H

#include<iostream>
#include<ctime>

#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"
#include"SFML/Window.hpp"

class Hitbox
{
public:
	Hitbox(sf::Sprite& sprite,
		float offset_x,float offset_y,
		float width,float height);

	~Hitbox();

	void Update();
	void Rander(sf::RenderTarget& target);
	bool checkIntersect(const sf::FloatRect& frect);

private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;

};

#endif // !HITBOX_H
