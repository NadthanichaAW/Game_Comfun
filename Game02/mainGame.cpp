#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include"Player.h"
#include"Platform.h"
#include"Item.h"
#include "stdlib.h"
#include"FireItem.h"
#include"Monster.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <utility>
using namespace std;

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
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Chivalry Girl", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HIGHT, VIEW_WIDE));

	//Texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/Martha9.png");

	sf::Vector2u textureSize = playerTexture.getSize();

	//Background_1
	sf::RectangleShape bg(sf::Vector2f(1248.0f, 1329.0f));
	bg.setPosition(0.0f, 0.0f);
	sf::Texture bgTexture;
	bgTexture.loadFromFile("Textures/BG_9.png");
	bg.setTexture(&bgTexture);

	//Background_2
	sf::RectangleShape bg2(sf::Vector2f(1248.0f, 1329.0f));
	bg2.setPosition(0.0f, 1329.0f);
	sf::Texture bg2Texture;
	bg2Texture.loadFromFile("Textures/BG_10.png");
	bg2.setTexture(&bg2Texture);

	//Background_3
	sf::RectangleShape bg3(sf::Vector2f(1248.0f, 1329.0f));
	bg3.setPosition(0.0f, 3000.0f);
	sf::Texture bg3Texture;
	bg3Texture.loadFromFile("Textures/BG_8.png");
	bg3.setTexture(&bg3Texture);

	//Frame
	window.setFramerateLimit(50);

	//Animation
	Player player(&playerTexture, sf::Vector2u(3, 8), 0.95f, 500.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	//Point - font
	int countCoin = 0;
	sf::Font font;
	font.loadFromFile("Textures/4Bit.ttf");
	std::ostringstream point;
	sf::Text Coin;
	Coin.setCharacterSize(50);
	Coin.setString(point.str());
	Coin.setFont(font);
	Coin.setFillColor(sf::Color::White);
	Coin.setOutlineColor(sf::Color(128, 128, 128));
	Coin.setOutlineThickness(1.0f);

	int countDimond = 0;
	int countClock = 0;
	
	sf::Text Clocke ;
	Clocke.setCharacterSize(50);
	Clocke.setString(point.str());
	Clocke.setFont(font);
	Clocke.setFillColor(sf::Color::White);
	Clocke.setOutlineColor(sf::Color(128, 128, 128));
	Clocke.setOutlineThickness(1.0f);

	//----------------------Score-------------------------------------------------
	sf::Font fontScore;
	fontScore.loadFromFile("Textures/XPLOR.ttf");
	std::ostringstream highscore;
	sf::Text youreScore;
	youreScore.setFont(fontScore);
	youreScore.setCharacterSize(50);
	youreScore.setFillColor(sf::Color(168, 11, 14));
	sf::RectangleShape score1(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape score2(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape score3(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape score4(sf::Vector2f(1080.0f, 720.0f));
	sf::Texture picScore1;
	picScore1.loadFromFile("Textures/score1.png");
	sf::Texture picScore2;
	picScore2.loadFromFile("Textures/score2.png");
	sf::Texture picScore3;
	picScore3.loadFromFile("Textures/score3.png");
	sf::Texture picScore4;
	picScore4.loadFromFile("Textures/score4.png");
	score1.setTexture(&picScore1);
	score2.setTexture(&picScore2);
	score3.setTexture(&picScore3);
	score4.setTexture(&picScore4);	
	
	//----------------------keyname-----------------------------------------
	sf::Font nameScore;
	nameScore.loadFromFile("Textures/NaughtyMonster.ttf");
	/*//sf::String playerInput;
	//std::ofstream fileWriter;
	//std::ostringstream keyname;
	sf::Text keyName;
	//keyName.setCharacterSize(40);
	keyName.setString(" ");
	keyName.setFont(nameScore);
	//keyName.setFillColor(sf::Color(168, 11, 14));
	sf::Text text("", nameScore);//mail thee pull ma 
	keyName.setPosition(300, 500);
	text.setFillColor(sf::Color(168,11,14));
	text.setPosition(545, 535);
	*/

	//Item
	sf::Texture coin;
	coin.loadFromFile("Textures/coin.png");
	sf::Texture clocker;
	clocker.loadFromFile("Textures/clock.png");
	sf::Texture chest;
	chest.loadFromFile("Textures/chest.png");
	std::vector<Item>coinVector;//���ǡ�������������������
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 520.0f, 500.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 560.0f, 500.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 560.0f, 530.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 560.0f, 560.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 560.0f, 630.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 520.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 480.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 520.0f, 670.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 352.0f, 470.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 352.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 480.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 480.0f, 840.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 190.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 220.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 260.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 310.0f, 720.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 352.0f, 840.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 312.0f, 880.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 312.0f, 930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 160.0f, 930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 200.0f, 930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 260.0f, 925.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 800.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 750.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 700.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 650.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 600.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 550.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 500.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 450.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 145.0f, 400.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 100.0f, 1170.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 65.0f, 1000.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 312.0f, 1050.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 725.0f, 500.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 725.0f, 550.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 725.0f, 600.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 685.0f, 600.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 780.0f, 600.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 685.0f, 635.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 725.0f, 680.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 737.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 787.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 837.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 887.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 937.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 987.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1037.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1087.0f, 722.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 890.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 940.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 990.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1040.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1090.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1140.0f, 590.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 890.0f, (rand() % 60 + 451)));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 940.0f, (rand() % 60 + 451)));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 995.0f, 464.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1045.0f, 464.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1095.0f, 464.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1145.0f, 464.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 907.0f, 382.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 957.0f, 382.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1007.0f, 382.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1057.0f, 382.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1107.0f, 382.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 973.0f, 1051.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1023.0f, 1051.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1073.0f, 1051.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1123.0f, 1051.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 957.0f, 1019.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 148.0f, 1019.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 198.0f, 1019.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 248.0f, 1019.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 298.0f, 1019.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 66.0f, 1215.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 116.0f, 1215.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 166.0f, 1215.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 216.0f, 1215.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 675.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 725.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 775.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 825.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 875.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 925.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 975.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1025.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1075.0f, 1522.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 780.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 830.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 880.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 930.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 980.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1030.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1080.0f, 1582.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 956.0f, 1627.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 956.0f, 1657.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 956.0f, 1687.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 956.0f, 1717.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 956.0f, 1747.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 675.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 715.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 755.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 795.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 835.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 875.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 915.0f, 1841.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 675.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 735.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 775.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 815.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 855.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 895.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 935.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 975.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1015.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1055.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1115.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1175.0f, 1930.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 675.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 735.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 795.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 855.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 915.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 975.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1035.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1095.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1155.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1195.0f, 2049.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 745.0f, 2109.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 795.0f, 2109.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 845.0f, 2109.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 895.0f, 2109.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 745.0f, 2161.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 795.0f, 2161.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 845.0f, 2161.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 895.0f, 2161.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1195.0f, 2089.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1195.0f, 2139.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1195.0f, 2189.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 1195.0f, 2239.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1736.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1786.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1836.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1886.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1936.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 1986.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2036.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2086.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2136.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2186.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2236.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2286.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 205.0f, 2336.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 1841.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 1891.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 1941.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 1991.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 2041.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 2091.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 2141.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 318.0f, 2191.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 1841.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 1891.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 1941.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 1991.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 2041.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 2091.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 2141.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 444.0f, 2191.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 1908.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 1958.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 2008.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 2058.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 2108.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 2158.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 137.0f, 2208.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 60.0f, 1886.99f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 60.0f, 1936.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 60.0f, 1986.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 60.0f, 2036.0f));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 65, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 115, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 165, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 215, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 265, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 315, 2555));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 69.99, 2597));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 119, 2597));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 169, 2597));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 219, 2597));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 269, 2597));
	coinVector.push_back(Item(&coin, sf::Vector2u(4, 1), 0.08f, sf::Vector2f(35.0f, 44.0f), 319, 2597));
	/**/

	//---------------------------clock----------------------------------------------
	std::vector<Item>ClockVector;
	ClockVector.push_back(Item(&clocker, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(35.0f, 44.0f), 892.0f, 1093.0f));
	ClockVector.push_back(Item(&clocker, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(35.0f, 44.0f), (rand() % 70 + 58), 920.0f));
	ClockVector.push_back(Item(&clocker, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(35.0f, 44.0f), 55.0f, (rand() % 200 + 385)));
	ClockVector.push_back(Item(&clocker, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(35.0f, 44.0f), 60.0f, 2132.0f));
	ClockVector.push_back(Item(&clocker, sf::Vector2u(4, 1), 0.15f, sf::Vector2f(35.0f, 44.0f), 625.0f, 2259.99f));
	/**/

	//-------------------------chest------------------------------------------------
	std::vector<Item>ChestVector;
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 141.99, 3501));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 346.99, 3596));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 225, 3890));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 638, 3520));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 735, 3595));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 1057.99, 3373.99));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 924.99, 3850));
	ChestVector.push_back(Item(&chest, sf::Vector2u(3, 2), 0.15f, sf::Vector2f(42.0f, 42.0f), 1178, 3085));

	//diamond
	sf::Texture diamond;
	diamond.loadFromFile("Textures/diamond2.png");
	std::vector<Item>diaVector;	
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 141.99, 3544));
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 346.99, 3544));
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 225, 3843));
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 638, 3565));
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 735, 3550));
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 1057.99, 3413.99)); 
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 924.99, 3807)); 
	diaVector.push_back(Item(&diamond, sf::Vector2u(3, 1), 0.15f, sf::Vector2f(30.0f, 30.0f), 1178, 3129)); 

	//Firepoint 
	sf::Texture FirePoint;
	FirePoint.loadFromFile("Textures/Firepoint3.png");
	std::vector<FireItem>fireVector;//���ǡ�������������������
	fireVector.push_back(FireItem(&FirePoint, sf::Vector2u(4, 1), 0.30, sf::Vector2f(32.0f, 192.0f), 555.0f, 406.0f));
	fireVector.push_back(FireItem(&FirePoint, sf::Vector2u(4, 1), 0.30, sf::Vector2f(32.0f, 192.0f), 690.0f, 406.0f));

	//Monster
	sf::Texture monsterSlim;
	monsterSlim.loadFromFile("Textures/Idle4.png");
	sf::Texture monstersFire;
	monstersFire.loadFromFile("Textures/firecommon.png");
	sf::Texture slimPurple;
	slimPurple.loadFromFile("Textures/slimpurple3.png");
	sf::Texture enermyP;
	enermyP.loadFromFile("Textures/EnermyP.png");
	sf::Texture enermyS;
	enermyS.loadFromFile("Textures/monsterS.png");
	sf::Texture wormE;
	wormE.loadFromFile("Textures/worm.png");
	sf::Texture titanRock;
	titanRock.loadFromFile("Textures/titanRock.png");
	sf::Texture pumkinHuman;
	pumkinHuman.loadFromFile("Textures/PumkinHuman.png");
	sf::Texture skeletonBlack;
	skeletonBlack.loadFromFile("Textures/monsterSkeB.png");
	sf::Texture slimGreen;
	slimGreen.loadFromFile("Textures/slimGreen.png");
	sf::Texture rockMons;
	rockMons.loadFromFile("Textures/rock.png");
	sf::Texture snailMons;
	snailMons.loadFromFile("Textures/snail.png");
	sf::Texture turtleMons;
	turtleMons.loadFromFile("Textures/turtle.png");

	std::vector<Monster>monsterVector;
	monsterVector.push_back(Monster(&monsterSlim, sf::Vector2u(13, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 188.0f, 711.0f));
	monsterVector.push_back(Monster(&monsterSlim, sf::Vector2u(13, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 886.0f, 580.0f));
	monsterVector.push_back(Monster(&monsterSlim, sf::Vector2u(13, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 492.0f, 850.0f));
	
	monsterVector.push_back(Monster(&monsterSlim, sf::Vector2u(13, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 195.0f, 2159.0f));
	monsterVector.push_back(Monster(&monsterSlim, sf::Vector2u(13, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 80.0f, 2583.0f));
	monsterVector.push_back(Monster(&rockMons, sf::Vector2u(14, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 789.0f, 1475.0f));
	monsterVector.push_back(Monster(&rockMons, sf::Vector2u(14, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 975.99f, 1937.0f));
	monsterVector.push_back(Monster(&rockMons, sf::Vector2u(14, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 581.00f, 1838.0f));
	
	monsterVector.push_back(Monster(&wormE, sf::Vector2u(3, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 95.0f, 380.0f));
	monsterVector.push_back(Monster(&wormE, sf::Vector2u(3, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 929.0f, 1125.0f));
	monsterVector.push_back(Monster(&wormE, sf::Vector2u(3, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 898.0f, 384.0f));
	
	std::vector<Monster>slimPvector;
	slimPvector.push_back(Monster(&slimPurple, sf::Vector2u(7, 2), 0.20, sf::Vector2f(52.0f, 50.0f), 500.0f, (rand() % 170 + 500)));
	slimPvector.push_back(Monster(&slimPurple, sf::Vector2u(7, 2), 0.20, sf::Vector2f(52.0f, 50.0f), 95.0f, (rand() % 80 + 596)));
	slimPvector.push_back(Monster(&slimPurple, sf::Vector2u(7, 2), 0.20, sf::Vector2f(52.0f, 50.0f), 93.0f, (rand() % 80 + 944)));
	slimPvector.push_back(Monster(&slimPurple, sf::Vector2u(7, 2), 0.20, sf::Vector2f(52.0f, 50.0f), 911.0f, 920.0f));
	slimPvector.push_back(Monster(&slimPurple, sf::Vector2u(7, 2), 0.20, sf::Vector2f(52.0f, 50.0f), 496, 201));
	
	slimPvector.push_back(Monster(&slimGreen, sf::Vector2u(10, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 209.0f, 1811.0f));
	slimPvector.push_back(Monster(&slimGreen, sf::Vector2u(10, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 664.0f, 2061.0f));
	slimPvector.push_back(Monster(&slimGreen, sf::Vector2u(10, 2), 0.20f, sf::Vector2f(52.0f, 50.0f), 550.0f, 1535.0f));

	std::vector<Monster>enermyVector;
	enermyVector.push_back(Monster(&enermyP, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 325.0f, 897.0f));
	enermyVector.push_back(Monster(&enermyP, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 910.0f, 678.0f));
	enermyVector.push_back(Monster(&enermyP, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 706.0f, 524.0f));

	enermyVector.push_back(Monster(&enermyS, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 268.0f, 417.0f));
	enermyVector.push_back(Monster(&enermyS, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 70.0f, 940.0f));
	enermyVector.push_back(Monster(&enermyS, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 55.0f, 401.0f));
	enermyVector.push_back(Monster(&enermyS, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 800.0f, 1900.0f));

	
	std::vector<Monster>skeletonVector;
	skeletonVector.push_back(Monster(&pumkinHuman, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 477.0f, 1851.0f));
	skeletonVector.push_back(Monster(&pumkinHuman, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 1180.0f, 1945.0f));

	skeletonVector.push_back(Monster(&skeletonBlack, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 208.0f, 1997.0f));
	skeletonVector.push_back(Monster(&skeletonBlack, sf::Vector2u(3, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 955.0f, 1655.0f));


	std::vector<Monster>titanrockVector;
	titanrockVector.push_back(Monster(&titanRock, sf::Vector2u(6, 2), 0.30, sf::Vector2f(102.0f, 100.0f), 85.0f, 1941.0f));
	titanrockVector.push_back(Monster(&titanRock, sf::Vector2u(6, 2), 0.30, sf::Vector2f(102.0f, 100.0f), 913.0f, 2530.0f));

	std::vector<Monster>animalVector;
	animalVector.push_back(Monster(&snailMons, sf::Vector2u(10, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 74.0f, 1585.0f));
	animalVector.push_back(Monster(&snailMons, sf::Vector2u(10, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 965.0f, 2008.0f));
	
	animalVector.push_back(Monster(&turtleMons, sf::Vector2u(8, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 914.0f, 1546.0f));
	animalVector.push_back(Monster(&turtleMons, sf::Vector2u(8, 2), 0.30, sf::Vector2f(62.0f, 60.0f), 238.0f, 2056.0f));
	
	//Icon
	sf::RectangleShape iconTimer(sf::Vector2f(355.0f, 126.0f));
	sf::Texture guiTimer;
	guiTimer.loadFromFile("Textures/timer.png");
	iconTimer.setTexture(&guiTimer);
	iconTimer.setSize(sf::Vector2f(167.5f, 63.0f));

	sf::RectangleShape iconCoin(sf::Vector2f(335.0f, 126.0f));
	sf::Texture guiCoin;
	guiCoin.loadFromFile("Textures/coin02.png");
	iconCoin.setTexture(&guiCoin);
	iconCoin.setSize(sf::Vector2f(167.5f, 63.0f));

	//Platform
	Collision playerCollision = player.GetCollision();
	Platform platform1(nullptr, sf::Vector2f(50.0f, 2658.0f), sf::Vector2f(5.0f,1329.0f));//�ѹ�á��Ҵ�ѹ�ͧpos left
	Platform platform2(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, -25.0f));//top
	Platform platform3(nullptr, sf::Vector2f(1248.0f, 50.0f), sf::Vector2f(624.0f, 1354.0f));//down 1329+25
	Platform platform4(nullptr, sf::Vector2f(50.0f, 2658.0f), sf::Vector2f(1243.0f, 1329.0f));//right 1248+25
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
	Platform platform17(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(414.0f, 767.0f));
	Platform platform18(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(414.99f, 640.99f));
	Platform platform19(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(415.0f, 515.99f));
	Platform platform20(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(540.0f, 767.0f));
	Platform platform21(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(416.0f, 890.99f));
	Platform platform22(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(249.0f, 806.99f));
	Platform platform23(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(706.0f, 767.0f));
	Platform platform24(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(831.0f, 767.0f));
	Platform platform25(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(831.0f, 891.0f));
	Platform platform26(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(831.0f, 640.99f));
	Platform platform27(nullptr, sf::Vector2f(45.0f, 45.0f), sf::Vector2f(831.0f, 516.0f));
	Platform platform28(nullptr, sf::Vector2f(129.0f, 45.0f), sf::Vector2f(790.0f, 386.0f));
	Platform platform29(nullptr, sf::Vector2f(129.0f, 45.0f), sf::Vector2f(456.0f,386.0f));
	Platform platform30(nullptr, sf::Vector2f(220.0f, 65.0f), sf::Vector2f(788.99f, 285.0f));
	Platform platform31(nullptr, sf::Vector2f(350.0f, 30.0f), sf::Vector2f(1036.0f, 305.0f));
	Platform platform32(nullptr, sf::Vector2f(190.0f, 45.0f), sf::Vector2f(1058.0f, 640.99f));
	Platform platform33(nullptr, sf::Vector2f(60.0f, 135.0f), sf::Vector2f(82.00f, 809.0f));
	Platform platform34(nullptr, sf::Vector2f(145.0f, 85.0f), sf::Vector2f(209.0f, 1121.0f));
	Platform platform35(nullptr, sf::Vector2f(105.0f, 45.0f), sf::Vector2f(1060.0f, 974.0f));
	Platform platform36(nullptr, sf::Vector2f(130.0f, 73.0f), sf::Vector2f(498.0f,959.0f));
	Platform platform37(nullptr, sf::Vector2f(165.0f, 73.0f), sf::Vector2f(769.0f, 959.0f));
	Platform platform38(nullptr, sf::Vector2f(20.0f, 73.0f), sf::Vector2f(553.0f, 945.0f));
	Platform platform39(nullptr, sf::Vector2f(20.0f, 73.0f), sf::Vector2f(694.0f, 945.0f));
	Platform platform40(nullptr, sf::Vector2f(50.0f, 286.0f), sf::Vector2f(832.0f, 1091.0f));
	Platform platform41(nullptr, sf::Vector2f(50.0f, 286.0f), sf::Vector2f(416.0f, 1091.0f));
	Platform platform42(nullptr, sf::Vector2f(105.0f, 65.0f), sf::Vector2f(511.0f, 1146.0f));
	Platform platform43(nullptr, sf::Vector2f(450.0f, 63.0f), sf::Vector2f(230.0f, 1276.0f));
	Platform platform44(nullptr, sf::Vector2f(450.0f, 63.0f), sf::Vector2f(1036.0f, 1276.0f));
	Platform platform45(nullptr, sf::Vector2f(62.0f, 122.0f), sf::Vector2f(537.0f, 1246.0f));
	Platform platform46(nullptr, sf::Vector2f(62.0f, 122.0f), sf::Vector2f(703.0f, 1246.0f));
	Platform platform47(nullptr, sf::Vector2f(105.0f, 65.0f), sf::Vector2f(738.0f, 1146.0f));
	Platform platform48(nullptr, sf::Vector2f(12.0f, 115.0f), sf::Vector2f(312.0f, 472.0f));
	Platform platform49(nullptr, sf::Vector2f(12.0f, 115.0f), sf::Vector2f(104.0f, 472.0f));
	Platform platform50(nullptr, sf::Vector2f(12.0f, 115.0f), sf::Vector2f(1186.0f,799.0f));
	Platform platform51(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(208.0f, 531.0f));
	Platform platform52(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(208.0f, 405.99f));
	Platform platform53(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1039.0f, 490.0f));
	Platform platform54(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1165.0f, 490.0f));
	Platform platform55(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1123.0f, 405.0f));
	Platform platform56(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(957.0f, 405.0f));
	Platform platform57(nullptr, sf::Vector2f(190.0f, 5.0f), sf::Vector2f(1065.0f, 739.99f));
	Platform platform58(nullptr, sf::Vector2f(145.0f, 5.0f), sf::Vector2f(1040.0f, 821.99f));
	Platform platform59(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1039.0f, 1155.0f));
	Platform platform60(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1165.0f, 1155.0f));
	Platform platform61(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(936.0f, 1155.0f));
	Platform platform62(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(1019.0f, 1072.0f));
	Platform platform63(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(1103.0f, 1072.0f));
	Platform platform64(nullptr, sf::Vector2f(5.0f, 5.0f), sf::Vector2f(1186.0f, 1072.0f));
	Platform platform65(nullptr, sf::Vector2f(5.0f, 45.0f), sf::Vector2f(936.0f, 1054.0f));
	Platform platform66(nullptr, sf::Vector2f(30.0f, 85.0f), sf::Vector2f(888.0f, 987.99f));
	Platform platform67(nullptr, sf::Vector2f(30.0f, 5.0f), sf::Vector2f(1144.0f, 864.0f));
	Platform platform68(nullptr, sf::Vector2f(30.0f, 95.0f), sf::Vector2f(519.0f, 26.0f));
	Platform platform69(nullptr, sf::Vector2f(30.0f, 95.0f), sf::Vector2f(732.0f, 26.0f));
	Platform platform70(nullptr, sf::Vector2f(166.0f, 32.0f), sf::Vector2f(607.0f, 9.0f));
	Platform platform71(nullptr, sf::Vector2f(32.0f, 81.0f), sf::Vector2f(539.0f, 30.0f));
	Platform platform72(nullptr, sf::Vector2f(32.0f, 81.0f), sf::Vector2f(690.0f,30.0f));
	Platform platform73(nullptr, sf::Vector2f(208.0f, 34.0f), sf::Vector2f(1092.0f, 9.0f));
	Platform platform74(nullptr, sf::Vector2f(208.0f, 34.0f), sf::Vector2f(128.0f, 9.0f));
	Platform platform75(nullptr, sf::Vector2f(1248.0f, 20.0f), sf::Vector2f(624.0f, 2660.0f));//down map2	
	Platform platform76(nullptr, sf::Vector2f(233.0f, 147.0f), sf::Vector2f(1131.0f, 1701.0f));
	Platform platform77(nullptr, sf::Vector2f(216.0f, 135.0f), sf::Vector2f(790.99f, 1701.0f));
	Platform platform78(nullptr, sf::Vector2f(33.0f, 14.0f), sf::Vector2f(1187.0f, 1551.0f));
	Platform platform79(nullptr, sf::Vector2f(74.0f, 14.0f), sf::Vector2f(1164.0f, 1465.0f));
	Platform platform80(nullptr, sf::Vector2f(500.0f, 14.0f), sf::Vector2f(998.0f, 1425.0f));
	Platform platform81(nullptr, sf::Vector2f(61.0f, 68.0f), sf::Vector2f(708.0f, 1391.0f));
	Platform platform82(nullptr, sf::Vector2f(61.0f, 68.0f), sf::Vector2f(540.0f, 1391.0f));
	Platform platform83(nullptr, sf::Vector2f(353.0f, 49.0f), sf::Vector2f(640.0f, 1655.99f));
	Platform platform84(nullptr, sf::Vector2f(183.99f, 45.0f), sf::Vector2f(395.0f, 1441.0f));
	Platform platform85(nullptr, sf::Vector2f(187.0f, 134.0f), sf::Vector2f(394.0f, 1645.0f));
	Platform platform86(nullptr, sf::Vector2f(186.99f, 47.0f), sf::Vector2f(531.0f, 1689.0f));
	Platform platform87(nullptr, sf::Vector2f(68.0f, 72.0f), sf::Vector2f(582.0f, 1741.99f));
	Platform platform88(nullptr, sf::Vector2f(74.0f, 292.0f), sf::Vector2f(579.0f, 2016.99f));
	Platform platform89(nullptr, sf::Vector2f(155.0f, 47.0f), sf::Vector2f(587.0f, 2189.0f));
	Platform platform90(nullptr, sf::Vector2f(156.0f, 68.0f), sf::Vector2f(624.0f, 2155.0f));
	Platform platform91(nullptr, sf::Vector2f(437.0f, 85.0f), sf::Vector2f(887.0f, 2248.0f));
	Platform platform92(nullptr, sf::Vector2f(154.0f, 167.0f), sf::Vector2f(1040.0f, 2165.0f));
	Platform platform93(nullptr, sf::Vector2f(142.0f, 55.0f), sf::Vector2f(1035.0f, 2302.0f));
	Platform platform94(nullptr, sf::Vector2f(94.0f, 100.0f), sf::Vector2f(1057.0f, 2332.0f));
	Platform platform95(nullptr, sf::Vector2f(64.0f, 136.0f), sf::Vector2f(1216.0f, 2360.0f));
	Platform platform96(nullptr, sf::Vector2f(157.0f, 40.0f), sf::Vector2f(958.0f, 2478.0f));
	Platform platform97(nullptr, sf::Vector2f(77.0f, 208.0f), sf::Vector2f(2394.0f, 913.0f));
	Platform platform98(nullptr, sf::Vector2f(600.0f, 108.0f), sf::Vector2f(561.0f, 2348.0f));
	Platform platform99(nullptr, sf::Vector2f(507.0f, 132.0f), sf::Vector2f(608.0f, 2400.0f));
	Platform platform100(nullptr, sf::Vector2f(154.0f, 113.0f), sf::Vector2f(466.0f, 2498.0f));
	Platform platform101(nullptr, sf::Vector2f(129.0f, 74.0f), sf::Vector2f(454.0f, 2621.0f));
	Platform platform102(nullptr, sf::Vector2f(61.0f, 27.0f), sf::Vector2f(531.0f, 2645.0f));
	Platform platform103(nullptr, sf::Vector2f(61.0f, 27.0f), sf::Vector2f(712.0f, 2645.0f));
	Platform platform104(nullptr, sf::Vector2f(133.0f, 356.0f), sf::Vector2f(787.0f, 2480.0f));
	Platform platform105(nullptr, sf::Vector2f(129.0f, 98.0f), sf::Vector2f(750.0f, 2490.0f));
	Platform platform106(nullptr, sf::Vector2f(140.0f, 100.0f), sf::Vector2f(70.0f, 2350.0f));
	Platform platform107(nullptr, sf::Vector2f(70.0f, 117.0f), sf::Vector2f(35.0f, 2429.0f));
	Platform platform108(nullptr, sf::Vector2f(73.0f, 39.0f), sf::Vector2f(288.0f, 2267.0f));
	Platform platform109(nullptr, sf::Vector2f(39.0f, 39.0f), sf::Vector2f(142.0f, 2267.0f));
	Platform platform110(nullptr, sf::Vector2f(74.0f, 49.0f), sf::Vector2f(292.0f, 1733.0f));
	Platform platform111(nullptr, sf::Vector2f(74.0f, 25.0f), sf::Vector2f(79.0f, 1717.0f));
	Platform platform112(nullptr, sf::Vector2f(69.0f, 32.0f), sf::Vector2f(35.0f, 1764.0f));
	Platform platform113(nullptr, sf::Vector2f(116.0f, 43.0f), sf::Vector2f(102.0f, 1811.99f));
	Platform platform114(nullptr, sf::Vector2f(288.0f, 39.0f), sf::Vector2f(179.0f, 1434.0f));
	Platform platform115(nullptr, sf::Vector2f(40.0f, 5.0f), sf::Vector2f(205.0f, 1490.0f));
	Platform platform116(nullptr, sf::Vector2f(32.0f, 23.0f), sf::Vector2f(271.0f, 1601.99f));
	Platform platform117(nullptr, sf::Vector2f(121.0f, 33.0f), sf::Vector2f(101.0f, 1521.99));
	Platform platform118(nullptr, sf::Vector2f(134.0f, 36.0f), sf::Vector2f(86.0f, 1644.99f));
	Platform platform119(nullptr, sf::Vector2f(73.0f, 76.0f), sf::Vector2f(998.0f, 2620.0f));
	Platform platform120(nullptr, sf::Vector2f(67.0f, 75.0f), sf::Vector2f(295.0f, 1666.0f));
	Platform platform121(nullptr, sf::Vector2f(1248.0f, 44.0f), sf::Vector2f(624.0f, 3010.0f));//topbg3
	Platform platform122(nullptr, sf::Vector2f(30.0f, 1319.0f), sf::Vector2f(0.0f, 3722.0f));//left
	Platform platform123(nullptr, sf::Vector2f(30.0f, 1319.0f), sf::Vector2f(1248.0f, 3722.0f));//right
	Platform platform124(nullptr, sf::Vector2f(1248.0f, 128.0f), sf::Vector2f(625.0f, 4265.0f));//down
	Platform platform125(nullptr, sf::Vector2f(420.0f, 32.0f), sf::Vector2f(893.0f, 3182.0f));
	Platform platform126(nullptr, sf::Vector2f(55.0f, 32.0f), sf::Vector2f(542.0f, 3182.0f));
	Platform platform127(nullptr, sf::Vector2f(227.0f, 32.0f), sf::Vector2f(792.0f, 3309.0f));
	Platform platform128(nullptr, sf::Vector2f(100.0f, 32.0f), sf::Vector2f(1061.0f, 3309.0f));
	Platform platform129(nullptr, sf::Vector2f(141.0f, 32.0f), sf::Vector2f(875.0f, 3472.99f));
	Platform platform130(nullptr, sf::Vector2f(99.0f, 32.0f), sf::Vector2f(1063.0f, 3472.99f));
	Platform platform131(nullptr, sf::Vector2f(99.0f, 32.0f), sf::Vector2f(1063.0f, 3641.99));
	Platform platform132(nullptr, sf::Vector2f(263.0f, 32.0f), sf::Vector2f(811.0f, 3641.99f));
	Platform platform133(nullptr, sf::Vector2f(93.0f, 64.0f), sf::Vector2f(813.0f, 3781.99f));
	Platform platform134(nullptr, sf::Vector2f(93.0f, 64.0f), sf::Vector2f(1063.0f, 3781.99f));
	Platform platform135(nullptr, sf::Vector2f(300.0f, 32.0f), sf::Vector2f(416.0f, 3309.0f));
	Platform platform136(nullptr, sf::Vector2f(213.0f, 32.0f), sf::Vector2f(333.0f, 3182.0f));
	Platform platform137(nullptr, sf::Vector2f(298.0f, 32.0f), sf::Vector2f(416.0f, 3641.99f));
	Platform platform138(nullptr, sf::Vector2f(85.0f, 32.0f), sf::Vector2f(144.0f, 3641.99f));
	Platform platform139(nullptr, sf::Vector2f(176.0f, 32.0f), sf::Vector2f(479.0f, 3764.0f));
	Platform platform140(nullptr, sf::Vector2f(67.0f, 8.0f), sf::Vector2f(240.0f, 3459.99f));
	Platform platform141(nullptr, sf::Vector2f(107.0f, 8.0f), sf::Vector2f(612.0f, 3459.99f));
	Platform platform142(nullptr, sf::Vector2f(52.0f, 32.0f), sf::Vector2f(165.0f, 3430.99f));
	Platform platform143(nullptr, sf::Vector2f(16.0f, 171.0f), sf::Vector2f(520.0f, 3111.99f));
	Platform platform144(nullptr, sf::Vector2f(16.0f, 44.0f), sf::Vector2f(728.0f, 3047.0f));
	Platform platform145(nullptr, sf::Vector2f(16.0f, 324.0f), sf::Vector2f(1105.0f, 3326.0f));
	Platform platform146(nullptr, sf::Vector2f(16.0f, 358.0f), sf::Vector2f(1020.0f, 3634.99f));
	Platform platform147(nullptr, sf::Vector2f(16.0f, 697.0f), sf::Vector2f(687.0f, 3649.99f));
	Platform platform148(nullptr, sf::Vector2f(16.0f, 280.0f), sf::Vector2f(144.0f, 3304.94f));
	Platform platform149(nullptr, sf::Vector2f(16.0f, 240.0f), sf::Vector2f(185.0f, 3533.99f));
	Platform platform150(nullptr, sf::Vector2f(47.0f, 198.0f), sf::Vector2f(124.0f, 3722.0f));
	Platform platform151(nullptr, sf::Vector2f(52.0f, 156.0f), sf::Vector2f(289.0f, 3701.0f));
	Platform platform152(nullptr, sf::Vector2f(16.0f, 298.0f), sf::Vector2f(269.0f, 3771.99f));
	Platform platform153(nullptr, sf::Vector2f(52.0f, 234.0f), sf::Vector2f(415.0f, 3532.0f));
	Platform platform154(nullptr, sf::Vector2f(16.0f, 156.0f), sf::Vector2f(561.0f, 3367.0f));
	Platform platform155(nullptr, sf::Vector2f(16.0f, 114.0f), sf::Vector2f(561.0f, 3596.99f));
	Platform platform156(nullptr, sf::Vector2f(16.0f, 123.0f), sf::Vector2f(561.0f, 3935.99f));
	Platform platform157(nullptr, sf::Vector2f(530.0f, 412.0f), sf::Vector2f(265.0f, 4123.0f));
	Platform platform158(nullptr, sf::Vector2f(530.0f, 329.0f), sf::Vector2f(983.0f, 4165.0f));
	Platform platform159(nullptr, sf::Vector2f(16.0f, 156.0f), sf::Vector2f(269.0f, 3367.0f));
	Platform platform160(nullptr, sf::Vector2f(496.0f, 55.0f), sf::Vector2f(248.0f, 3030.0f));
	Platform platform161(nullptr, sf::Vector2f(56.0f, 74.0f), sf::Vector2f(415.0f, 3783.99f));
	Platform platform162(nullptr, sf::Vector2f(110.0f, 2.0f), sf::Vector2f(625.0f, 3205.0f));
	Platform platform163(nullptr, sf::Vector2f(559.0f, 64.0f), sf::Vector2f(969.0f, 3949.0f));

	//heart
	sf::RectangleShape heartBar(sf::Vector2f(294.0f, 87.0f));
	sf::Texture guiHeart;
	guiHeart.loadFromFile("Textures/heart.png");
	heartBar.setTexture(&guiHeart);
	heartBar.setSize(sf::Vector2f(147.5f, 43.5f)); 
	sf::RectangleShape heartBar2(sf::Vector2f(294.0f, 87.0f));
	sf::Texture guiHeart2;
	guiHeart2.loadFromFile("Textures/heart2.png");
	heartBar2.setTexture(&guiHeart2);
	heartBar2.setSize(sf::Vector2f(147.5f, 43.5f));
	sf::RectangleShape heartBar3(sf::Vector2f(294.0f, 87.0f));
	sf::Texture guiHeart3;
	guiHeart3.loadFromFile("Textures/heart3.png");
	heartBar3.setTexture(&guiHeart3);
	heartBar3.setSize(sf::Vector2f(147.5f, 43.5f));
	sf::RectangleShape heartBar4(sf::Vector2f(294.0f, 87.0f));
	sf::Texture guiHeart4;
	guiHeart4.loadFromFile("Textures/heart4.png");
	heartBar4.setTexture(&guiHeart4);
	heartBar4.setSize(sf::Vector2f(147.5f, 43.5f));

	//---------------------------menu-------------------------------------------------
	sf::RectangleShape menu1(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape menu2(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape menu3(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape menu4(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape menu5(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape howtoplay(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape howtoplay2(sf::Vector2f(1080.0f, 720.0f));
	sf::Texture picMenu1;
	picMenu1.loadFromFile("Textures/menu.png");
	sf::Texture picMenu2;
	picMenu2.loadFromFile("Textures/menu2.png");
	sf::Texture picMenu3;
	picMenu3.loadFromFile("Textures/menu3.png");
	sf::Texture picMenu4;
	picMenu4.loadFromFile("Textures/menu4.png");
	sf::Texture picMenu5;
	picMenu5.loadFromFile("Textures/menu5.png");
	sf::Texture pichowto;
	pichowto.loadFromFile("Textures/howtoplay.png");
	sf::Texture pichowto2;
	pichowto2.loadFromFile("Textures/howtoplay2.png");
	menu1.setTexture(&picMenu1);
	menu2.setTexture(&picMenu2);
	menu3.setTexture(&picMenu3);
	menu4.setTexture(&picMenu4);
	menu5.setTexture(&picMenu5);
	howtoplay.setTexture(&pichowto);
	howtoplay2.setTexture(&pichowto2);

	//----------------------------leaderbordandname----------------------------
	sf::RectangleShape enterN(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape enterN2(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape leadBord(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape leadBord2(sf::Vector2f(1080.0f, 720.0f));
	sf::RectangleShape loading(sf::Vector2f(1080.0f, 720.0f));
	sf::Texture picName;
	picName.loadFromFile("Textures/name.png");
	sf::Texture picName2;
	picName2.loadFromFile("Textures/name2.png");
	sf::Texture picBord;
	picBord.loadFromFile("Textures/leaderbord.png");
	sf::Texture picBord2;
	picBord2.loadFromFile("Textures/leaderbord2.png");
	sf::Texture picLoad;
	picLoad.loadFromFile("Textures/loading.png");
	enterN.setTexture(&picName);
	enterN2.setTexture(&picName2);
	leadBord.setTexture(&picBord);
	leadBord2.setTexture(&picBord2);
	loading.setTexture(&picLoad);


	//---------------------------Sound-----------------------------------------
	sf::SoundBuffer sound;
	sound.loadFromFile("Textures/coin.wav");
	sf::Sound soundCoin;
	soundCoin.setBuffer(sound);
	soundCoin.setVolume(30.0f);

	sf::Music titleSound;
	titleSound.openFromFile("Textures/soundBGM.wav");
	titleSound.setVolume(30.0f);
	titleSound.setLoop(true);

	sf::Music bonustimeSound;
	bonustimeSound.openFromFile("Textures/bonustime.wav");
	bonustimeSound.setVolume(30.0f);
	bonustimeSound.setLoop(true);
	
	sf::Music gameoverSound;
	gameoverSound.openFromFile("Textures/gameover 8bit.wav");
	gameoverSound.setVolume(30.0f);

	sf::Music levelclearSound;
	levelclearSound.openFromFile("Textures/levelclear.wav");
	levelclearSound.setVolume(30.0f);

	sf::Music mainmenuSound;
	mainmenuSound.openFromFile("Textures/mainsound.wav");
	mainmenuSound.setVolume(30.0f);
	
	//-----------------------keyname---------------------------------
	sf::String playerInput;
	std::ofstream fileWriter;
	std::ostringstream keyname;
	sf::Text Keyname;
	Keyname.setCharacterSize(40);
	Keyname.setString(" ");
	Keyname.setFont(nameScore);
	Keyname.setFillColor(sf::Color::Black);
	Keyname.setPosition(300, 500);
	char last_char = ' ';
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5.0f, 30.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 15.0f));
	cursor.setFillColor(sf::Color::White);
	sf::Text text("", nameScore);
	text.setFillColor(sf::Color::White);
	text.setPosition(430, 415);
	cursor.setPosition(430.0f + text.getGlobalBounds().width + 10, 435.0f);
	float totalTime_cursor = 0;
	sf::Clock clock_cursor;
	
	std::string user_name = "";
	std::fstream myFile;
	std::map<int, std::string> keepscore;
	std::ifstream fileReader;
	std::string word;

	//----------------------------TIME---------------
	sf::Clock nubClock;
	sf::Clock hitClock;
	sf::Clock guiClock;
	sf::Clock loadClock;


	bool backMenu = false;
	bool loadingTime = false;
	bool leadState = false;
	bool state_cursor = false;
	bool nameState = false;
	bool bordScore = false;
	bool howto = false;
	bool menu = true;
	bool start = false;
	bool dieSound = false;
	bool soundEnd = false;
	bool endGame = false;
	bool drawDia = false;
	bool checkMap = false;
	bool checkMap2 = false;
	int countNames = 0;
	int countLead = 0;
	int dieStart = 0;
	int soundStart = 0;
	int bonusScore = 0;
	int numofCycle = 0;
	int u = 0;

	while (window.isOpen())
	{
		mainmenuSound.play();
		while (menu==true)
		{
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			
			window.draw(menu1);	
			if (howto == false)
			{
				if (sf::Mouse::getPosition(window).x >= 460 && sf::Mouse::getPosition(window).y >= 507 && sf::Mouse::getPosition(window).x <= 620 && sf::Mouse::getPosition(window).y <= 580)
				{
					//play
					window.draw(menu2);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && guiClock.getElapsedTime().asSeconds() > 0.3)
					{
						menu = false;
						start = false;
						nameState = true;
						hitClock.restart();
					}
				}
				if (sf::Mouse::getPosition(window).x >= 460 && sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).x <= 620 && sf::Mouse::getPosition(window).y <= 670)
				{
					window.draw(menu3);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && guiClock.getElapsedTime().asSeconds() > 0.3)
					{
						//exit
						window.close();
						break;
					}
				}
				if (sf::Mouse::getPosition(window).x >= 916 && sf::Mouse::getPosition(window).y >= 640 && sf::Mouse::getPosition(window).x <= 980 && sf::Mouse::getPosition(window).y <= 705)
				{
					//how to 
					window.draw(menu5);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						howto = true;
					}
				}
				if (sf::Mouse::getPosition(window).x >= 995 && sf::Mouse::getPosition(window).y >= 640 && sf::Mouse::getPosition(window).x <= 1060 && sf::Mouse::getPosition(window).y <= 705)
				{
					//score
					window.draw(menu4);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						leadState = true;
						menu = false;
						start = false;
					}
				}
			}
			
			if (howto == true)
			{
				window.draw(howtoplay);
				if (sf::Mouse::getPosition(window).x >= 444 && sf::Mouse::getPosition(window).y >= 543 && sf::Mouse::getPosition(window).x <= 640 && sf::Mouse::getPosition(window).y <= 635)
				{
					window.draw(howtoplay2);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						howto = false;
						guiClock.restart();
					}
				}
			}
			window.display();
		}

		while (leadState == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			if (countLead == 0)
			{
				view.setCenter(540, 360);
			}
			
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
			window.clear();
			window.draw(menu1);
			window.draw(leadBord);		
			if (sf::Mouse::getPosition(window).x >= 444 && sf::Mouse::getPosition(window).y >= 543 && sf::Mouse::getPosition(window).x <= 640 && sf::Mouse::getPosition(window).y <= 635)
			{
				window.draw(leadBord2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					nameState = false;
					leadState = false;
					menu = true;
					guiClock.restart();
				}
			}
			sf::Text text1("", nameScore);
			text1.setCharacterSize(45);
			text1.setFillColor(sf::Color::White);
			fileReader.open("Textures/leaderbordScore.txt");
			do
			{
				fileReader >> word;
				std::string first_token = word.substr(0, word.find(','));
				int second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				keepscore[second_token] = first_token;
			} while (fileReader.good());
			fileReader.close();
			std::map<int, std::string>::iterator end = keepscore.end();
			std::map<int, std::string>::iterator beg = keepscore.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
				text1.setString(it->second);//name
				text1.setPosition(view.getCenter().x - 195, 250 + 80 * currentDisplay);
				window.draw(text1);
				text1.setString(std::to_string(it->first)); //score
				text1.setPosition(view.getCenter().x + 75, 250 + 80 * currentDisplay);
				window.draw(text1);
				currentDisplay++;
				if (currentDisplay == 5)
				{
					break;
				}
			}
			window.display();
		}

		while (nameState == true) 
		{
			countNames += deltaTime;
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;
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
			if (event.type == sf::Event::TextEntered && last_char != event.text.unicode)
			{
				if (event.text.unicode == 13)
				{ //enter
					user_name = playerInput;
					playerInput.clear();
					menu = true;
				}
				else if (event.text.unicode == 8 && playerInput.getSize() >= 0) 
				{ // backspace delete
					playerInput = playerInput.substring(0, playerInput.getSize() - 1);
				}
				else 
				{
					if (playerInput.getSize() < 15) 
					{
						playerInput += event.text.unicode;
						countNames = 0;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{	
					loadingTime = true;	
					loadClock.restart();

				}
				last_char = event.text.unicode;
				text.setString(playerInput);
				cursor.setPosition(430.0f + text.getGlobalBounds().width + 10, 435.0f);
			}
			else if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ') 
			{
				last_char = ' ';
			}
			window.clear();
			window.draw(enterN);
			window.draw(Keyname);
	
			totalTime_cursor += clock_cursor.restart().asSeconds();
			if (totalTime_cursor >= 0.5) 
			{
				totalTime_cursor = 0;
				state_cursor = !state_cursor;
			}
			if (state_cursor == true) 
			{
				window.draw(cursor);
			}
			window.draw(text);
			if (loadingTime == true)
			{
				window.draw(loading);
				if (loadClock.getElapsedTime().asSeconds() > 0.8)
				{
					leadState = false;
					menu = false;
					nameState = false;
					start = true;
				}
				titleSound.play();
			}
			window.display();
		}
		deltaTime = 0;
		clock.restart();

		while (start == true)
		{
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			mainmenuSound.stop();
			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl		
			
			window.draw(bg);
			window.draw(bg2);
			window.draw(bg3);
	
			//Item
			for (int i = 0; i < ChestVector.size(); i++)
			{
				ChestVector[i].chestHit(deltaTime, player);
			}
		
			for (int i = 0; i < coinVector.size(); i++)
			{
				coinVector[i].drawItem(window);
			}
			for (int i = 0; i < ClockVector.size(); i++)
			{
				ClockVector[i].drawItem(window);
			}
			for (int i = 0; i < fireVector.size(); i++)
			{
				fireVector[i].drawItemFire(window);
			}
			for (int i = 0; i < enermyVector.size(); i++)
			{
				enermyVector[i].drawMonster(window);
			}
			for (int i = 0; i < slimPvector.size(); i++)
			{
				slimPvector[i].drawMonster(window);
			}
			for (int i = 0; i < monsterVector.size(); i++)
			{
				monsterVector[i].drawMonster(window);
			}

			for (int i = 0; i < ChestVector.size(); i++)
			{
				ChestVector[i].drawItem(window);
			}
			if (ChestVector[0].drawDia() == true)
			{				
					diaVector[0].drawItem(window);
					diaVector[0].updateDiamond(deltaTime, player);
					drawDia = true;
			}
			if (ChestVector[1].drawDia() == true)
			{
					diaVector[1].drawItem(window);
					diaVector[1].updateDiamond(deltaTime, player);
					drawDia = true;

			}
			if (ChestVector[2].drawDia() == true)
			{
					diaVector[2].drawItem(window);
					diaVector[2].updateDiamond(deltaTime, player);
					drawDia = true;
			}
			if (ChestVector[3].drawDia() == true)
			{
				diaVector[3].drawItem(window);
				diaVector[3].updateDiamond(deltaTime, player);
				drawDia = true;
			}
			if (ChestVector[4].drawDia() == true)
			{
				diaVector[4].drawItem(window);
				diaVector[4].updateDiamond(deltaTime, player);
				drawDia = true;
			}
			if (ChestVector[5].drawDia() == true)
			{
				diaVector[5].drawItem(window);
				diaVector[5].updateDiamond(deltaTime, player);
				drawDia = true;
			}
			if (ChestVector[6].drawDia() == true)
			{
				diaVector[6].drawItem(window);
				diaVector[6].updateDiamond(deltaTime, player);
				drawDia = true;
			}
			if (ChestVector[7].drawDia() == true)
			{
				diaVector[7].drawItem(window);
				diaVector[7].updateDiamond(deltaTime, player);
				drawDia = true;
			}
			for (int i = 0; i < titanrockVector.size(); i++)
			{
				titanrockVector[i].drawMonster(window);
			}
			for (int i = 0; i < skeletonVector.size(); i++)
			{
				skeletonVector[i].drawMonster(window);
			}
			for (int i = 0; i < animalVector.size(); i++)
			{
				animalVector[i].drawMonster(window);
			}
			player.Draw(window);
			window.draw(iconTimer);
			window.draw(iconCoin);
			window.draw(Coin);
			window.draw(Clocke);
			window.draw(heartBar);
			if (player.hpHeart() == 1)
			{
				window.draw(heartBar2);
			}
			else if (player.hpHeart() == 2)
			{
				window.draw(heartBar3);
			}
			else if (player.hpHeart() == 3)
			{
				//endGame = true;
				window.draw(heartBar4);
				for (; dieStart < 1; dieStart++)
				{
					dieSound = true;
				}

			}
			if (dieSound == true)
			{
				titleSound.stop();
				gameoverSound.play();

			}dieSound = false;

			point.str(" ");
			point << "  " << countCoin + countDimond;
			Coin.setString(point.str());
			iconCoin.setPosition({ view.getCenter().x + 350,view.getCenter().y - 360 });
			Coin.setPosition({ view.getCenter().x + 400,view.getCenter().y - 367 });
			for (int i = 0; i < coinVector.size(); i++)
			{
				if (coinVector[i].pointCoins() == 1)
				{
					soundCoin.play();
					countCoin += 100;
				}
			}
			for (int i = 0; i < diaVector.size(); i++)
			{
				if (diaVector[i].pointDiamond() == 1)
				{
					soundCoin.play();
					countDimond += 500;
				}
			}
			point.str(" ");

			if (checkMap2 == false)
			{
				point << "  " << countClock;
			}
			if (checkMap2 == true)
			{
				bonusScore = countClock - int(nubClock.getElapsedTime().asSeconds());
				point << "  " << bonusScore;
				if (countClock - int(nubClock.getElapsedTime().asSeconds()) == 0)
				{
					endGame = true;
					for (; soundStart < 1; soundStart++)
					{
						soundEnd = true;
					}
				}/**/

			}
			if (soundEnd == true)
			{
				bonustimeSound.stop();
				levelclearSound.play();

			}
			soundEnd = false;
			//------------------------endscore------------------------------------------
			if (endGame == true)
			{
				nubClock.restart();
				countClock = 0;
				highscore.str(" ");
				highscore << "  " << countCoin + countDimond;
				youreScore.setString(highscore.str());
				window.draw(score1);

				if (sf::Mouse::getPosition(window).x >= 444 && sf::Mouse::getPosition(window).y >= 574 && sf::Mouse::getPosition(window).x <= 495 && sf::Mouse::getPosition(window).y <= 620)
				{
				
					window.draw(score2);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
				
						printf("STUPID JING JING E KWAI");
						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							printf("....12345............");
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("Textures/leaderbordScore.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << countCoin + countDimond;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();
					}
				}
				if (sf::Mouse::getPosition(window).x >= 512 && sf::Mouse::getPosition(window).y >= 574 && sf::Mouse::getPosition(window).x <= 564 && sf::Mouse::getPosition(window).y <= 620)
				{
					window.draw(score3);
				}
				if (sf::Mouse::getPosition(window).x >= 583 && sf::Mouse::getPosition(window).y >= 574 && sf::Mouse::getPosition(window).x <= 636 && sf::Mouse::getPosition(window).y <= 620)
				{
					window.draw(score4);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						window.close();
						break;
					}
				}

				window.draw(youreScore);
				youreScore.setPosition({ view.getCenter().x - 105,view.getCenter().y + 115 });
				score1.setPosition({ view.getCenter().x - 540,view.getCenter().y - 360 });
				score2.setPosition({ view.getCenter().x - 540,view.getCenter().y - 360 });
				score3.setPosition({ view.getCenter().x - 540,view.getCenter().y - 360 });
				score4.setPosition({ view.getCenter().x - 540,view.getCenter().y - 360 });
			}

			Clocke.setString(point.str());
			iconTimer.setPosition({ view.getCenter().x + 150,view.getCenter().y - 360 });
			Clocke.setPosition({ view.getCenter().x + 200,view.getCenter().y - 367 });
			for (int i = 0; i < ClockVector.size(); i++)
			{
				if (ClockVector[i].pointClocks() == 1)
				{

					soundCoin.play();
					countClock += 10;
				}
			}
			heartBar.setPosition({ view.getCenter().x + 360,view.getCenter().y - 290 });
			heartBar2.setPosition({ view.getCenter().x + 360,view.getCenter().y - 290 });
			heartBar3.setPosition({ view.getCenter().x + 360,view.getCenter().y - 290 });
			heartBar4.setPosition({ view.getCenter().x + 360,view.getCenter().y - 290 });
			
			window.setView(view);
			window.display();

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
				checkMap = true;
				u = 1;
				player.SetPosition(625, 1410);
				//player.SetPosition(958, 1671);
			}if (u == 1)
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
			//warp in map 2
			if ((player.GetPosition().x > 880 && player.GetPosition().x < 904) && player.GetPosition().y >= 2617 && player.GetPosition().y <= 2618)
			{
				player.SetPosition(623.41, 2617);
			}
			//warp to bg3
			if ((player.GetPosition().x > 580 && player.GetPosition().x < 660) && player.GetPosition().y >= 2520 && player.GetPosition().y <= 2550)
			{
				nubClock.restart();
				checkMap2 = true;
				titleSound.stop();
				bonustimeSound.play();
				u = 2;
				player.SetPosition(625, 3136);
			}if (u == 2)
			{
				view.setCenter(player.GetPosition());//x=y
				if (view.getCenter().x - 540.0f <= 0.0f)//front center window behide pic
				{
					if (view.getCenter().y - 360.0f <= 0.0f)
					{
						view.setCenter(540.0f, 360.0f);//window
					}
					if (view.getCenter().y + 360.0f >= 4329.0f)
					{
						view.setCenter(540.0f, 3969.0f);//window
					}
					if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 4329.0f)
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
					if (view.getCenter().y + 360.0f >= 4329.0f)
					{
						view.setCenter(708.0f, 3969.0f);//window 1248-540
					}
					if (view.getCenter().y - 360.0f > 0.0f && view.getCenter().y + 360.0f < 4329.0f)
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
					if (view.getCenter().y + 360.0f >= 4329.0f)
					{
						view.setCenter(player.GetPosition().x, 3969.0f);
					}
				}
			}


			/*if (checkMap == false)
			{
				player.updateSlimFire(deltaTime, monsterFVector);
				player.updateSlimP(deltaTime, slimPvector);
				player.updateMonS(deltaTime, monsterVector);
				player.updateEnermies(deltaTime, enermyVector);
				player.updateFire(deltaTime, fireVector);
			}
			if (checkMap == true)
			{
				player.updateEnermies2(deltaTime, enermyVector, monsterVector, titanrockVector, skeletonVector, slimPvector, animalVector);

			}
			*/



			if (endGame == false)
			{
				if (hitClock.getElapsedTime().asSeconds() > 0.5)
				{
					player.Update(deltaTime);
				}
					//Itemupdate	
				for (int i = 0; i < coinVector.size(); i++)
				{
					coinVector[i].updateItem(deltaTime, player);
				}
				for (int i = 0; i < ClockVector.size(); i++)
				{
					ClockVector[i].updateItem(deltaTime, player);
				}
				for (int i = 0; i < slimPvector.size(); i++)
				{
					slimPvector[i].updateXslim(deltaTime);
				}
				for (int i = 0; i < monsterVector.size(); i++)
				{
					monsterVector[i].updateXMons(deltaTime);
				}
				for (int i = 0; i < enermyVector.size(); i++)
				{
					enermyVector[i].updateEnermy(deltaTime);
				}
			
					
				for (int i = 0; i < fireVector.size(); i++)
				{
					fireVector[i].updateItemFire(deltaTime);
				}
				for (int i = 0; i < titanrockVector.size(); i++)
				{
					titanrockVector[i].updatetitanRock(deltaTime);
				}
				for (int i = 0; i < skeletonVector.size(); i++)
				{
					skeletonVector[i].updateSkeleton(deltaTime);
				}
				for (int i = 0; i < animalVector.size(); i++)
				{
					animalVector[i].updateAnimal(deltaTime);
				}
				
			}


			//PlatformCollision
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
			platform16.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform17.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform18.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform18.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform19.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform20.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform21.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform22.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform23.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform24.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform25.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform26.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform27.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform28.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform29.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform30.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform31.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform32.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform33.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform34.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform35.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform36.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform37.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform38.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform39.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform40.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform41.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform42.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform43.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform44.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform45.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform46.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform47.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform48.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform49.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform50.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform51.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform52.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform53.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform54.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform55.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform56.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform57.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform58.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform59.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform60.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform61.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform62.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform63.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform64.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform65.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform66.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform67.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform68.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform69.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform70.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform71.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform72.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform73.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform74.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform75.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform76.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform77.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform78.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform79.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform80.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform81.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform82.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform83.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform84.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform85.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform86.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform87.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform88.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform89.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform90.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform91.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform92.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform93.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform94.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform95.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform96.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform97.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform98.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform99.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform100.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform101.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform102.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform103.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform104.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform105.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform106.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform107.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform108.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform109.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform110.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform111.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform112.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform113.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform114.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform115.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform116.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform117.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform118.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform119.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform120.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform121.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform122.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform123.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform124.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform125.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform126.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform127.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform128.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform129.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform130.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform131.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform132.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform133.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform134.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform135.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform136.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform137.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform138.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform139.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform140.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform141.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform142.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform143.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform144.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform145.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform146.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform147.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform148.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform149.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform150.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform151.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform152.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform153.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform154.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform155.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform156.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform157.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform158.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform159.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform160.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform161.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform162.GetCollision().CheckCollision(playerCollision, 1.0f);
			platform163.GetCollision().CheckCollision(playerCollision, 1.0f);

			window.clear();
		}
	}	
		return 0;
}
	
