#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include"Player.h"
#include"Platform.h"
#include"Item.h"
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>

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
	

	//Texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/Martha9.png");
	
	//View
	/*view.setCenter(sf::Vector2f(0.0f, 0.0f));
	view.setSize(sf::Vector2f(200.f, 200.f));
	*/
	sf::Vector2u textureSize = playerTexture.getSize();

	//Background_1
	sf::RectangleShape bg(sf::Vector2f(1248.0f, 1329.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture bgTexture;
	bgTexture.loadFromFile("Textures/bg4.png");
	bg.setTexture(&bgTexture);
	
	//Background_2
	sf::RectangleShape bg2(sf::Vector2f(1248.0f, 1329.0f));
	bg2.setPosition(0.0f, 1329.0f);
	sf::Texture bg2Texture;
	bg2Texture.loadFromFile("Textures/BG_7.png");
	bg2.setTexture(&bg2Texture);

	//Frame
	window.setFramerateLimit(120);

	//Animation
	Player player(&playerTexture, sf::Vector2u(3, 8), 0.3f,500.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	//Point
	int countPoint = 0;
	sf::Font font;
	font.loadFromFile("Textures/ALGER.ttf");
	std::ostringstream point;
	sf::Text Coin;
	Coin.setCharacterSize(50);
	Coin.setString(point.str());
	Coin.setFont(font);
	Coin.setFillColor(sf::Color::White);
	
	//Sound
	sf::SoundBuffer sound;
	sound.loadFromFile("Textures/coin.wav");
	sf::Sound soundCoin;
	soundCoin.setBuffer(sound);
	soundCoin.setVolume(50.0f);

	//Item
	sf::Texture coin;
	coin.loadFromFile("Textures/coin.png");
	std::vector<Item>ItemVector;//ใช้เวกเตอร์เพราะมีหลายไอเท็ม
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 520.0f, 500.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 560.0f, 500.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 560.0f, 530.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 560.0f, 560.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 560.0f, 630.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 520.0f, 590.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 480.0f, 590.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 520.0f, 670.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 352.0f, 470.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 352.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 480.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 480.0f, 840.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 190.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 220.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 260.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 310.0f, 720.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 352.0f, 840.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 312.0f, 880.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 312.0f, 930.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 160.0f, 930.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 200.0f, 930.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 260.0f, 925.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 800.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 750.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 700.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 650.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 600.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 550.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 500.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 450.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 145.0f, 400.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 100.0f, 1170.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 65.0f, 1000.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 312.0f, 1050.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 725.0f, 500.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 725.0f, 550.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 725.0f, 600.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 685.0f, 600.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 780.0f, 600.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 685.0f, 635.0f));
	ItemVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, 725.0f, 680.0f));



	//Platform
	Collision playerCollision = player.GetCollision();
	Platform platform1(nullptr, sf::Vector2f(50.0f, 1329.0f), sf::Vector2f(5.0f, 664.5f));//อันแรกขนาดอันสองpos left
	Platform platform2(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, -25.0f));//top
	Platform platform3(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, 1354.0f));//down 1329+25
	Platform platform4(nullptr, sf::Vector2f(50.0f, 1329.0f), sf::Vector2f(1243.0f,664.5f));//right 1248+25
	Platform platform5(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(210.0f, 180.0f));
	Platform platform6(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(85.0f, 180.0f));
	Platform platform7(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(60.0f, 130.0f));
	Platform platform8(nullptr, sf::Vector2f(55.0f, 30.0f), sf::Vector2f(250.0f, 140.0f));
	Platform platform9(nullptr, sf::Vector2f(220.0f, 100.0f), sf::Vector2f(370.0f, 65.0f));
	Platform platform10(nullptr, sf::Vector2f(50.0f, 35.0f), sf::Vector2f(1042.0f, 180.0f));
	Platform platform11(nullptr, sf::Vector2f(45.0f, 35.0f), sf::Vector2f(1165.0f, 180.0f));
	Platform platform12(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(1185.0f, 130.0f));
	Platform platform13(nullptr, sf::Vector2f(55.0f, 30.0f), sf::Vector2f(1000.0f, 140.0f));
	Platform platform14(nullptr, sf::Vector2f(220.0f, 100.0f), sf::Vector2f(880.0f, 65.0f));
	Platform platform15(nullptr, sf::Vector2f(350.0f, 30.0f), sf::Vector2f(190.0f, 305.0f));
	Platform platform16(nullptr, sf::Vector2f(220.0f, 65.0f), sf::Vector2f(460.0f, 285.0f));

	int u = 0;
	while (window.isOpen())
	{
		
		deltaTime = clock.restart().asSeconds();
		sf::Vector2f pos = player.GetPosition();
		std::cout << pos.x << ' ' << pos.y << '\n';
		//view.setSize(720.0f, 720.0f);
		//view.zoom(0.5f);
		window.draw(bg);
		window.draw(bg2);
		
		/*if ((player.GetPosition().x > 592 && player.GetPosition().x < 660) && player.GetPosition().y >= 1271 && player.GetPosition().y <= 1299)
		{
			u = 1;
			player.SetPosition(140, 100);
			//window.draw(bg2);
		}
		if (u == 1) {
			window.draw(bg2);
		}*/
		
		window.draw(Coin);
		player.Draw(window);
		
		//Item
		for (int i = 0; i < ItemVector.size(); i++)
		{
			ItemVector[i].drawItem(window);
		}

		//Point
		point.str(" ");
		point << "Coin : " << countPoint;
		Coin.setString(point.str());
		Coin.setPosition({ view.getCenter().x-540,view.getCenter().y-360});
		for (int i = 0; i < ItemVector.size(); i++)
		{
			if (ItemVector[i].iscollide() == 1)
			{
				soundCoin.play();
				countPoint += 100;
			}
		}

		//platformDraw
		//platform1.Draw(window);
		platform2.Draw(window);
		//platform3.Draw(window);
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
		//platform16.Draw(window);


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
		//warp to bg2
		if ((player.GetPosition().x > 592 && player.GetPosition().x < 660) && player.GetPosition().y >= 1271 && player.GetPosition().y <= 1299)
		{
			u = 1;
			player.SetPosition(625, 1410);
			//player.SetPosition(958, 1671);
		}if (u==1)
		{
			view.setCenter(player.GetPosition());//x=y
			if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
			{
				if (view.getCenter().y - 360.0f <= 0.0f)
				{
					view.setCenter(540.0f, 360.0f);//window
				}
				if (view.getCenter().y + 360.0f >= 2658.0f)
				{
					view.setCenter(540.0f, 2298.0f);//window
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 2658.0f)
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
				if (view.getCenter().y + 360.0f >= 2658.0f)
				{
					view.setCenter(708.0f, 2298.0f);//window 1248-540
				}
				if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 2658.0f)
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
				if (view.getCenter().y + 360.0f >= 2658.0f)
				{
					view.setCenter(player.GetPosition().x, 2298.0f);
				}
			}
		}

		player.Update(deltaTime);

		//Itemupdate
		for (int i = 0; i < ItemVector.size(); i++)
		{
			ItemVector[i].update(deltaTime, player);
		}

		//PlatformCollision
		platform1.GetCollision().CheckCollision(playerCollision, 1.0f);
		platform2.GetCollision().CheckCollision(playerCollision, 1.0f);
		//platform3.GetCollision().CheckCollision(playerCollision, 1.0f);
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
		platform16.GetCollision().CheckCollision(playerCollision, 1.0f);

		window.clear();
	
	}
	return 0;
}