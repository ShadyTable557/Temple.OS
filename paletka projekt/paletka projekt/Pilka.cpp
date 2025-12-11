#include "pilka.h"
#include "ceg³a.h"
#include <cmath>

Pilka::Pilka(float x, float y, float vx, float vy, float radius) 
: x(x), y(y), vx(vx), vy(vy), radius(radius)
{
	shape.setRadius(radius);
	shape.setOrigin({ radius, radius });
	shape.setPosition({ x, y });
	shape.setFillColor(sf::Color::Yellow);

}
bool Pilka::collideBrick(Cegla& cegla)
{
	if (!cegla.getIsAlive()) return false;

	if (x + radius >= cegla.getLeft() && x - radius <= cegla.getRight() &&
		y + radius >= cegla.getTop() && y - radius <= cegla.getBottom())
	{
		
		float overlapX = std::min(x + radius - cegla.getLeft(), cegla.getRight() - (x - radius));
		float overlapY = std::min(y + radius - cegla.getTop(), cegla.getBottom() - (y - radius));

		if (overlapX < overlapY)
		{
			
			bounceX();
		}
		else
		{
			
			bounceY();
		}

		cegla.hit();
		return true;
	}
	return false;
}

void Pilka::move() //funkcja ruchu pi³ki
{
	x += vx;
	y += vy;
	shape.setPosition({ x, y });
}

void Pilka::bounceX() //odbicie poziome
{
	vx = -vx;
}

void Pilka::bounceY() //odbicie pionowe
{
	vy = -vy;
}





void Pilka::collideWalls(float width, float height) //logika odbijania od granic okna
{
	if (x - radius <= 0 || x + radius >= width) //odbicie od œciany 
	{
		bounceX();
	}
	if (y - radius <= 0) //odbicie od sufitu
	{
		bounceY();
	}
}


bool Pilka::collidePaddle(const Paletka& p)
{
	float x1 = p.getX();					//przeniesienie gettery paletki do klasy pi³ki
	float y1 = p.getY();					//
	float szerokosc = p.getSzerokosc() / 2;	//
	float wysokosc = p.getWysokosc() / 2;	//
	float paletkaLewo = x1 - szerokosc;			//dane pomocnicze
	float paletkaPrawo = x1 + szerokosc;		//
	float paletkaDol = y1 + wysokosc;			//
	float paletkaGora = y1 - wysokosc;			//
	const float minVx = vx/1.2;
	if (x >= paletkaLewo && x <= paletkaPrawo)
	{
		if (y + radius >= paletkaGora && y + radius <= paletkaDol) 
		{ 
			float odchylenie = x - x1;
			float odchylenieMax = szerokosc;
			float normalizacja = odchylenie / odchylenieMax;
			float vx2 = normalizacja * vx;

			if (std::abs(vx2) < minVx) /*if pilnujacy aby pilka nie zamknela sie w loopie gora-dol*/
			{
				if (vx2 < 0)
				{
					vx = -minVx;
				}
				else
				{
					vx = minVx;
				}
			


			}

			vy = -std::abs(vy);
			y = paletkaGora - radius - 0.1f;
			shape.setPosition({ x,y });
			return true;
		}
		
	
	}
	return false;
	
}

void Pilka::draw(sf::RenderTarget& target)
{
	target.draw(shape);
}
