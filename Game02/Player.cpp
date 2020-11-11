#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
    
	this->speed = speed;
	row = 0;
    attack = false;
    faceDirection = 1; //row 1 หันหน้าลง 
    r = 1;
    //hitbox = 0;

	body.setSize(sf::Vector2f(65.0f, 65.0f));
	body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(140.0f, 100.0f);
   //body.setPosition(1110.0f, 100.0f);
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
        faceDirection == 4;
        movement.x -= speed * deltaTime;
        attack = false;
      
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        faceDirection == 3;
        movement.x += speed * deltaTime;
        attack = false;
      
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        faceDirection == 2;
        movement.y -= speed * deltaTime;
        attack = false;
     
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        faceDirection == 1;
        movement.y += speed * deltaTime;
        attack = false;
      
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        attack = true;
        std::cout << "attack!!!";
    }

    //hitbox
    if (attack == true) 
    {
        if (faceDirection==1)
        {
            r == 1;
            row = 4;
    
        }
        else if (faceDirection==2)
        {
            r == 2;
            row = 7;
        
        }
        else if (faceDirection==3)
        {
            r == 3;
            row = 5;
          
        }
        else if (faceDirection==4)
        {
            r == 4;
            row = 6;
        
        }      
    }
    else
    {
        if (movement.y > 0.0f)
        {    
            faceDirection = 1;
            row = 0;
          
        }
        else if (movement.y < 0.0f)
        {
            faceDirection = 2;
            row = 3;
         
        }
        else if (movement.x > 0.0f )
        {
            faceDirection = 3;
            row = 1;
         
        }
        else if (movement.x < 0.0f )
        {
            faceDirection = 4;
            row = 2;
        }
    }
   /* if (movement.y != 0)
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
    
    if (body.getPosition().x < 25.f)
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
  
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::SetPosition(float x, float y)
{
    body.setPosition(x, y);
}

void Player::setSizes(float w, float h)
{
    body.setSize(sf::Vector2f(w, h));

}

void Player::updateMonster(float deltatime, std::vector<Monster>& monsterVector)
{
    for (int i = 0; i < monsterVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(monsterVector[i].GetCollider()))
        {
            body.setPosition(140.0f, 100.0f);            
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);

}
