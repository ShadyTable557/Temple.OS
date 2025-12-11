#pragma once
#include <SFML/Graphics.hpp>
#include "paletka.h"
class Cegla;
class Pilka
{
private:
	float x;
	float y;//pozycja startowa pi³ki, wspolrzedne srodka
	float vx;
	float vy;//prêdkoœci w osiach
	float radius; //promieñ pi³ki
	sf::CircleShape shape;
public:

	Pilka(float x, float y, float vx, float vy, float radius);

	bool collideBrick(Cegla& cegla);

	void move(); //funkcja ruchu pi³ki

	void bounceX(); //odbicie poziome
	
	void bounceY(); //odbicie pionowe

	void collideWalls(float width, float height); //logika odbijania od granic okna

	bool collidePaddle(const Paletka& p);

	void draw(sf::RenderTarget& target);

	float getpX() const { return x; }
	float getpY() const { return y; }
	float getpVx() const { return vx; }
	float getpVy() const { return vy; }
	float getRadius() const { return radius; }
};