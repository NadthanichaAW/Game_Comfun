#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
    this->hpCount = 0;
	this->speed = speed;
	row = 0;
    attack = false;
    faceDirection = 1; //row 1 หันหน้าลง 

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
        if (faceDirection == 1)
        {
            row = 4;
        }
        else if (faceDirection == 2)
        {
            row = 7;

        }
        else if (faceDirection == 3)
        {
            row = 5;
        }
        else if (faceDirection == 4)
        {
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
            else if (movement.x > 0.0f)
            {
                faceDirection = 3;
                row = 1;

            }
            else if (movement.x < 0.0f)
            {
                faceDirection = 4;
                row = 2;
            }        
    }  
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

void Player::updateSlimFire(float deltatime, std::vector<Monster>& monsterFVector)
{
    for (int i = 0; i < monsterFVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(monsterFVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(140.0f, 100.0f);            
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);

}

void Player::updateSlimP(float deltatime, std::vector<Monster>& slimPvector)
{
    for (int i = 0; i < slimPvector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(slimPvector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(140.0f, 100.0f);
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);
}

void Player::updateMonS(float deltatime, std::vector<Monster>& monsterVector)
{
    for (int i = 0; i < monsterVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(monsterVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(140.0f, 100.0f);
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);

}

void Player::updateEnermies(float deltatime, std::vector<Monster>& enermyVector)
{
    for (int i = 0; i < enermyVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(enermyVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(140.0f, 100.0f);
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);
}

void Player::updateFire(float deltatime, std::vector<FireItem>& fireVector)
{
    for (int i = 0; i < fireVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(fireVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(140.0f, 100.0f);
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);
}
void Player::updateEnermies2(float deltatime, std::vector<Monster>& enermyVector, std::vector<Monster>& monsterVector,std::vector<Monster>& titanrockVector,std::vector<Monster>& skeletonVector,std::vector<Monster>& slimPvector, std::vector<Monster>& animalVector)//map 2 
{
    for (int i = 0; i < slimPvector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(slimPvector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    for (int i = 0; i < animalVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(animalVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    for (int i = 0; i < skeletonVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(skeletonVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    for (int i = 0; i < titanrockVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(titanrockVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    for (int i = 0; i < monsterVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(monsterVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    for (int i = 0; i < enermyVector.size(); i++)
    {
        if (this->GetCollision().CheckCollision(enermyVector[i].GetCollider()))
        {
            this->hpCount++;
            body.setPosition(600.0f, 1400.0f);
        }
    }
    animation.updateItem(row, deltatime);
    body.setTextureRect(animation.uvRect);
}