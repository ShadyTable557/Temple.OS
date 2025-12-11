//#pragma once
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <iostream>
//
//const int szerokoscOkna{ 680 }, wysokoscOkna{ 480 };
//
//int main()
//{
//	//tworzenie okna
//	sf::RenderWindow window(sf::VideoMode({ szerokoscOkna, wysokoscOkna }), "pilka paletka");
//	window.setFramerateLimit(60);
//
//	while (window.isOpen())
//	{
//		while (const optional event = window.pollEvent())
//		{
//			if (event->is<sf::Event::Closed>())
//				window.close();
//		}
//		window.display();
//	}
//	return 0;
//}