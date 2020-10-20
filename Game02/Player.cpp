#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0;
	faceTop = false;
	faceRight = true;
	
	body.setSize(sf::Vector2f(65.0f, 65.0f));
	body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(140.0f, 100.0f);
   // body.setPosition(1110.0f, 100.0f);
	body.setTexture(texture);

}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        movement.x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        faceTop = true;
        movement.y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        movement.y += speed * deltaTime;
    }

    if (movement.x == 0 && movement.y == 0)
    {
        row = 0;
    }
    else
    {
        if (movement.y != 0)
        {
            row = 0;
            if (movement.y > 0.0f)
            {
                faceTop = false;
            }
            if (movement.y < 0.0f)
            {
                faceTop = true;
                row = 3;
            }
        }
        if (movement.x > 0.0f && movement.y == 0.0f)
        {
            row = 1;
            faceRight = true;
        }
        if (movement.x < 0 && movement.y == 0.0f)
        {
            row = 2;
            faceRight = true;
        }
    }
    /*if (body.getPosition().x < 25.f)
    {
        body.setPosition(25.f, body.getPosition().y);
    } 
    if (body.getPosition().y< 25.f)
    {
        body.setPosition(body.getPosition().x,25.f);
    }
    if (body.getPosition().x + body.getGlobalBounds().width > 745.0f)
    {
        body.setPosition(745.0f - body.getGlobalBounds().width, body.getPosition().y);
    } 
    if (body.getPosition().y + body.getGlobalBounds().height > 745.0f)
    {
        body.setPosition(body.getPosition().x, 745.0f - body.getGlobalBounds().height);
    }*/
  
	animation.Update(row, deltaTime, faceRight, faceTop);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
