#pragma once
#include <SFML/Graphics.hpp>

class Paletka
{
private:
	float x; //wspó³rzêdne x y œrodka paletki 
	float y; //
	float szerokosc;
	float wysokosc;
	float predkosc;
	sf::RectangleShape paletka;

public:

	Paletka(float x, float y, float szerokosc, float wysokosc, float predkosc); /*: x(x), y(y), szerokosc(szerokosc), wysokosc(wysokosc), predkosc(predkosc)*/

	void moveLeft();
	
	void moveRight();

	void clampToBounds(float width);

	void draw(sf::RenderTarget& target);


	float getX() const { return x; }
	float getY() const { return y; }
	float getSzerokosc() const { return szerokosc; }
	float getWysokosc() const { return wysokosc; }
	float getPredkosc() const { return predkosc; }
	
};
