
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "pilka.h"
#include "paletka.h"
#include "cegła.h"
#include <vector>
#include <random>
using namespace std;

int main()
{

	const int szerokoscOkna{ 680 }, wysokoscOkna{ 480 }; //tworzenie okna
	sf::RenderWindow window(sf::VideoMode({ szerokoscOkna, wysokoscOkna }), "pilka paletka");
	window.setFramerateLimit(60);
	sf::Clock clock;



	Paletka paletka(320.f, 480.f, 100.f, 20.f, 8.f); 
	Pilka shape(320.f, 200.f, 4.f, 3.f, 8.f); 
	const float BRICK_HEIGHT = 20.f;
	const float PADDING = 10.f;
	const int BRICKS_PER_ROW = 8;
	const int NUM_ROWS = 4;
	const float usableWidth = szerokoscOkna - (BRICKS_PER_ROW + 1) * PADDING;
	const float brickWidth = usableWidth / BRICKS_PER_ROW;

	vector<Cegla> bricks;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 3); 

	for (int row = 0; row < NUM_ROWS; ++row)
	{
		for (int col = 0; col < BRICKS_PER_ROW; ++col)
		{
			float brickX = PADDING + (brickWidth / 2) + col * (brickWidth + PADDING);
			float brickY = 50.f + (BRICK_HEIGHT / 2) + row * (BRICK_HEIGHT + PADDING); 

			bricks.emplace_back(brickX, brickY, brickWidth, BRICK_HEIGHT, distrib(gen));
		}
	}


	while (window.isOpen())
	{
		sf::Time delta_time = clock.restart();
		float dt = delta_time.asSeconds();

		//********************Obsługa zdarzeń******************************//
		while (const optional event = window.pollEvent()) 
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		//****************************************************************//


		//***********************************Wczytywanie klawiszy********************//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{													  	
			paletka.moveLeft();								  
		}													  
															  
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{													  
			paletka.moveRight();							  
		}													  
		//***************************************************************************//


		shape.move(); //inicjacja ruchu piłki//

		shape.collideWalls(szerokoscOkna, wysokoscOkna);

		if (shape.collidePaddle(paletka))	//inicjacja logiki odbicia piłki od paletki//
		{
			cout << "Hit paddle!\n";
		}

		paletka.clampToBounds(szerokoscOkna);  //inicjacja stopy paletki na granicach okna//


		if (shape.getpY() - shape.getRadius() > wysokoscOkna) // Poprawiony warunek
		{
			std::cout << "MISS! KONIEC GRY\n";
			window.close();
		}

		for (auto& brick : bricks)
		{
			shape.collideBrick(brick);
		}

		window.clear(sf::Color(20, 20, 30));
		paletka.draw(window);
		shape.draw(window);

		for (auto& brick : bricks)
		{
			brick.draw(window);
		}
		window.display();
	}
	return 0;
};
