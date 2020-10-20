#include <SFML/Graphics.hpp>
#include <iostream>
#include"Player.h"
#include"Platform.h"

static const float VIEW_HIGHT = 1080.0f;
static const float VIEW_WIDE = 720.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HIGHT * aspectRatio, VIEW_HIGHT);
	view.setSize(VIEW_WIDE * aspectRatio, VIEW_WIDE);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Chivalry Girl", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HIGHT, VIEW_WIDE));
	
	/*sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Magenta);
	player.setOrigin(50.0f, 50.0f);//µ”·ÀπËß‡¡“ Ï
	*/
	//Texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/Martha2.png");
	
	//View
	/*view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(200.f, 200.f));
	*/
	sf::Vector2u textureSize = playerTexture.getSize();

	//Background
	/*sf::Texture bgWorld;
	sf::Sprite bg;
	bgWorld.loadFromFile("Textures/bg3.png");
	bg.setTexture(bgWorld);
	*/
	sf::RectangleShape bg(sf::Vector2f(1248.0f, 1329.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture bgTexture;
	bgTexture.loadFromFile("Textures/bg4.png");
	bg.setTexture(&bgTexture);
	/*sf::Texture bgTexture;
	sf::Sprite bg;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;
	if (!bgTexture.loadFromFile("Textures/Texture01.png"))
	{
		return -1;
	}
	else
	{
		TextureSize = bgTexture.getSize();
		WindowSize = window.getSize();
		bg.setTextureRect(sf::IntRect(0, 0, 400, 333));
		float scaleX = (float)WindowSize.x / TextureSize.x;
		float scaleY = (float)WindowSize.y / TextureSize.y;
		bg.setTexture(bgTexture);
		bg.setScale(scaleX, scaleY);
	}*/
	//sprite
	//textureSize.x /= 6;
	//textureSize.y /= 4;
	//player.setTextureRect(sf::IntRect(textureSize.x*4,textureSize.y*6,textureSize.x,textureSize.y));
	//player.scale(0.5f, 0.5f);

	//Frame
	window.setFramerateLimit(120);
	//float dt;
	//sf::Clock dt_clock;
	//const float gridSize = 50.0f;

	//Animation
	Player player(&playerTexture, sf::Vector2u(6, 4), 0.3f,120.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	//Platform
	Collision playerCollision = player.GetCollision();
	Platform platform1(nullptr, sf::Vector2f(50.0f, 1329.0f), sf::Vector2f(5.0f, 664.5f));//Õ—π·√°¢π“¥Õ—π Õßpos left
	Platform platform2(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, -25.0f));//top
	Platform platform3(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, 1354.0f));//down 1329+25
	Platform platform4(nullptr, sf::Vector2f(50.0f, 1329.0f), sf::Vector2f(1243.0f,664.5f));//right 1248+25
	Platform platform5(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(210.0f, 180.0f));
	Platform platform6(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(85.0f, 180.0f));
	Platform platform7(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(60.0f, 130.0f));
	Platform platform8(nullptr, sf::Vector2f(55.0f, 30.0f), sf::Vector2f(250.0f, 140.0f));
	Platform platform9(nullptr,sf::Vector2f(220.0f,100.0f),sf::Vector2f(370.0f,65.0f));
	Platform platform10(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(1042.0f, 180.0f));
	Platform platform11(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(1165.0f, 180.0f));
	Platform platform12(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(1185.0f, 130.0f));
	Platform platform13(nullptr, sf::Vector2f(55.0f, 30.0f), sf::Vector2f(1000.0f, 140.0f));
	Platform platform14(nullptr, sf::Vector2f(220.0f, 100.0f), sf::Vector2f(880.0f, 65.0f));
	Platform platform15(nullptr, sf::Vector2f(350.0f, 30.0f), sf::Vector2f(190.0f, 305.0f));
	while (window.isOpen())
	{
		
		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';
		//view.setSize(720.0f, 720.0f);
		//view.zoom(0.5f);
		window.draw(bg);
		player.Draw(window);
		
		//platformDraw
		//platform1.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);
		//platform4.Draw(window);
		//platform5.Draw(window);
		//platform6.Draw(window);
		//platform7.Draw(window);
		//platform8.Draw(window);
		//platform9.Draw(window);
		//platform10.Draw(window);
		//platform11.Draw(window);
		//platform12.Draw(window);
		//platform13.Draw(window);
		//platform14.Draw(window);
		//platform15.Draw(window);
		window.setView(view);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			case sf::Event::TextEntered:
				break;
			}
		}
		view.setCenter(player.GetPosition());//x=y
		if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(540.0f, 360.0f);//window
			}
			if (view.getCenter().y + 360.0f >= 1329.0f)
			{
				view.setCenter(540.0f, 969.0f);//window
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1329.0f)
			{
				view.setCenter(540.0f, player.GetPosition().y);
			}

		}
		if (view.getCenter().x + 540.0f >= 1248.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(708.0f, 360.0f);//window 1248-540 collision right 
			}
			if (view.getCenter().y + 360.0f >= 1329.0f)
			{
				view.setCenter(708.0f, 969.0f);//window 1248-540
			}
			if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 1329.0f)
			{
				view.setCenter(708.0f, player.GetPosition().y);
			}
		}
		if (view.getCenter().x - 540.0f > 0.0f && view.getCenter().x + 540.0f < 1248.0f)
		{
			if (view.getCenter().y - 360.0f <= 0.0f)
			{
				view.setCenter(player.GetPosition().x, 360.0f);
			}
			if (view.getCenter().y + 360.0f >= 1329.0f)
			{
				view.setCenter(player.GetPosition().x, 969.0f);
			}
		}

		player.Update(deltaTime);
		
		platform1.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform2.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform3.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform4.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform5.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform6.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform7.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform8.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform9.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform10.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform11.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform12.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform13.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform14.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform15.GetCollision().CheckCollision(playerCollision, 1.0f);
		//view.setCenter(player.GetPosition());
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			sprite.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			sprite.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			sprite.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			sprite.move(0.0f, 0.1f);
		}*/
		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);
		}*/
		window.clear();
	
	}
	return 0;
}