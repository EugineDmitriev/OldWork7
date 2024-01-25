#include<iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

const int height = 15;
const int width = 64;

char tilemap[height][width] = {
	"o                                                              ",
	"                                                               ",
	"                                    ooooooooooooooooooooooooooo",
	"                                                               ",
	"                                                               ",
	"                o                                              ",
	"               ooo                                             ",
	"              ooooo                                            ",
	"             ooooooo                                           ",
	"             bbbbbbb                                           ",
	"             bb b bb                                           ",
	"             bbbbbbb                                           ",
	"             bbbbbbb                                           ",
	"ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt",
	"ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt",
};


/*const int height = 8;
const int width = 16;

char tilemap[height][width] = {
"              e",
"               ",
"               ",
"tt  ttotttt  tt",
"ooooooooooooooo",
"otttototooootto",
"ooooootoooooooo",
"tt tttotttttttt"
};*/




Image im;
Texture t;
Sprite s;
Texture t2;
Sprite play_map;
Image en;
Image en1;
Texture te;
Texture te1;
Sprite se;
Sprite se1;
Image apple_i;
Texture apple_t;
Sprite apple_s;

class Hero
{
public:
	void player();

};

void Hero::player()
{
	
	im.loadFromFile("D:\\cpp\\chip_anime3.png");
	im.createMaskFromColor(Color::White);
	t.loadFromImage(im);
	s.setTexture(t);
	s.setTextureRect(IntRect(35, 0, 35, 48));
	//s.setPosition(0, 575);
	s.setPosition(width * 0, height * 38.5);
};

class Background
{
public:
	void background();
};

void Background::background()
{
	t2.loadFromFile("D:\\cpp\\tileset.png");
	play_map.setTexture(t2);
};

class EnemyA
{
public:
	void Enemy();
};

void EnemyA::Enemy()
{
	en.loadFromFile("D:\\cpp\\enemy1a.png");
	en.createMaskFromColor(Color::White);
	te.loadFromImage(en);
	se.setTexture(te);
	se.setTextureRect(IntRect(240, 0, 240, 60));
	se.setPosition(750, 565);
	//se.setPosition(width * 12, height * 37.7);
};

class EnemyB
{
public:
	void Enemy1();
};

void EnemyB::Enemy1()
{
	en1.loadFromFile("D:\\cpp\\enemy2a.png");
	en1.createMaskFromColor(Color::White);
	te1.loadFromImage(en1);
	se1.setTexture(te1);
	se1.setTextureRect(IntRect(0, 0, 123, 48));
	//se1.setPosition(750, 265);
	se1.setPosition(width * 10, height * 38.5);
};


class Colision
{
public:
	void ColisionMap();

};

/*void Colision::ColisionMap()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (tilemap[i][j] == 'b') {
				if (s.getPosition().x == width*10)
				{
					s.move(0, 0);
				}
			}
		}
	}
};*/



class Apple
{
public:
	void apple();
};

void Apple::apple()
{
	apple_i.loadFromFile("D:\\cpp\\object1.png");
	apple_i.createMaskFromColor(Color::White);
	apple_t.loadFromImage(apple_i);
	apple_s.setTexture(apple_t);
	apple_s.setTextureRect(IntRect(0, 0, 48, 47));
	//apple_s.setPosition(150, 375);
	apple_s.setPosition(width * 5, height * 38.5);
}






int main()
{
	//int resolutionW = 565, resolutionH = 390;
	int resolutionW = 1280, resolutionH = 720;
	sf::RenderWindow window(sf::VideoMode(resolutionW, resolutionH), "Main");
	//sf::RenderWindow window(sf::VideoMode(200, 200), "Main");
	//sf::RenderWindow window(sf::VideoMode(565, 390), "Main");

	float Frame = 0;
	Clock cl;


	Hero pl;
	pl.player();
	Background bg;
	bg.background();

	EnemyA EnA;
	EnA.Enemy();

	EnemyB EnB;
	EnB.Enemy1();

	/*Colision CoL;
	CoL.ColisionMap();*/

	Apple app;
	app.apple();

	int count = 0;
	int count1 = 10;

	int countEnemy = 0;
	int countEnemy1 = 6;
	int countEnemyA = 0;
	int countEnemyA1 = 6;


	int dirEnemy=1;
	int dirEnemyA = 1;

	int countApple = 0;
	

	while (window.isOpen())
	{
		//window.setVerticalSyncEnabled(true);
		window.setFramerateLimit(20);
		float time = cl.getElapsedTime().asMicroseconds();
		cl.restart();
		time = time / 10000;
	

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			count++;
			s.setTextureRect(IntRect(35 * count, 0, 35, 48));
			if (count == 3)
			{
				count = 0;	
			}
			if (s.getPosition().x <= resolutionW - 35)
			{
				s.move(10, 0);
				if (s.getPosition().x == apple_s.getPosition().x)
				{
					if (Keyboard::isKeyPressed(Keyboard::F) || countApple==1)
					{
						apple_s.move(10, 0);
						countApple = 1;
					}
				}
			}
		}
		
	


		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (countApple == 1)
			{
				countApple = 0;
			}
			count1--;
			s.setTextureRect(IntRect(35 * count1, 0, 35, 48));
			if (count1 == 6)
			{
				count1 = 10;
			}
			if (s.getPosition().x >= 0)
			{
				s.move(-10, 0);
				if (s.getPosition().x == apple_s.getPosition().x)
				{
						if (Keyboard::isKeyPressed(Keyboard::F))
						{
							apple_s.move(-10, 0);
						}
				}
			}
		}



		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (s.getPosition().y >= 0)
			{
				s.move(0, -1);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (s.getPosition().y <= resolutionH - 48)
			{
				s.move(0, 1);
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			count++;
			s.setTextureRect(IntRect(35 * count, 0, 35, 48));
			if (count == 3)
			{
				count = 0;
			}
			if (s.getPosition().x <= resolutionW - 35)
			{
				s.move(10, -5);
				
				s.move(5, 5);
			}
		}





		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}




		window.clear(Color::White);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (tilemap[i][j] == ' ') {
					play_map.setTextureRect(IntRect(35 * 0, 0, 35, 48));
				}
				if (tilemap[i][j] == 't') {
					play_map.setTextureRect(IntRect(35 * 3, 0, 35, 48));
				}
				if (tilemap[i][j] == 'o') {
					play_map.setTextureRect(IntRect(35 * 1, 0, 35, 48));
				}
				if (tilemap[i][j] == 'b') {
					play_map.setTextureRect(IntRect(35 * 2, 0, 35, 48));
				}
				play_map.setPosition(j * 35, i * 48);
				window.draw(play_map);
			}
		}


	////////////////////////////////////////////////////////////////////////////////////////////////////////	
		

			if (dirEnemy == 1)
			{
				if (countEnemy == 3) {
					countEnemy = 0;
				}
				else if (countEnemy < 3) {
					se.setTextureRect(IntRect(80 * countEnemy, 0, 80, 60));                    //width * 12, height * 37.7

					countEnemy = countEnemy++;
				if /*(se.getPosition().x>=width*10)	*/ (se.getPosition().x >= 700)
					{
						se.move(-10, 0);
					}
				}
			}

			if /*(se.getPosition().x==width*10)*/ (se.getPosition().x == 700)
			{
				dirEnemy = 0;
			}


		 if (dirEnemy == 0)
			{
				if (countEnemy1 == 6) {
					countEnemy1 = 3;
				}
				else if (countEnemy1 < 6) {
					se.setTextureRect(IntRect(80 * countEnemy1, 0, 80, 60));

					countEnemy1 = countEnemy1++;

					if /*(se.getPosition().x <= width * 14)*/  (se.getPosition().x <= 900)
					{
						se.move(10, 0);
					}
				}
			}

		 if /*(se.getPosition().x == width * 14)*/  (se.getPosition().x == 900)
		{
			dirEnemy = 1;
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			  if (dirEnemyA == 1)
			  {
				  if (countEnemyA == 3) {
					  countEnemyA = 0;
				  }
				  else if (countEnemyA < 3) {
					  se1.setTextureRect(IntRect(41 * countEnemyA, 0, 41, 48));
					  if (se1.getPosition().x >= 300)
					  {
						  se1.move(-10, 0);
					  }
					  countEnemyA = countEnemyA++;
				  }
			  }

			  if (se1.getPosition().x == 300)
			  {
				  dirEnemyA = 0;
			  }


			  if (dirEnemyA == 0)
			  {
				  if (countEnemyA1 == 6) {
					  countEnemyA1 = 3;
				  }
				  else if (countEnemyA1 < 6) {
					  se1.setTextureRect(IntRect(41 * countEnemyA1, 0, 41, 48));
					  if (se1.getPosition().x <= 1000)
					  {
						  se1.move(10, 0);
					  }
					  countEnemyA1 = countEnemyA1++;
				  }
			  }

			  if (se1.getPosition().x == 1000)
			  {
				  dirEnemyA = 1;
			  }



			
			  
			  window.draw(apple_s);
		      window.draw(se1);
			  window.draw(se);
			  window.draw(s);
			  window.display();

		}
	

	return 0;
}
