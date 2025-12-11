#include "paletka.h"

Paletka::Paletka(float x, float y, float szerokosc, float wysokosc, float predkosc)
	: x(x), y(y), szerokosc(szerokosc), wysokosc(wysokosc), predkosc(predkosc)
{
	paletka.setSize({ szerokosc, wysokosc });
	paletka.setOrigin({ szerokosc / 2, wysokosc / 2 });
	paletka.setPosition({ x,y });
	paletka.setFillColor(sf::Color::Magenta);
}

void Paletka::draw(sf::RenderTarget& target)
{
	target.draw(paletka);
}
void Paletka::moveLeft()
{
	x = x - predkosc;
	paletka.setPosition({ x,y });
}
void Paletka::moveRight()
{
	x = x + predkosc;
	paletka.setPosition({ x,y });
}
void Paletka::clampToBounds(float width)
{
	if (x - szerokosc / 2 < 0)
		{
		x = szerokosc / 2;
		}

	if (x + szerokosc / 2 > width)
		{
		x = width - szerokosc / 2;
		}
	paletka.setPosition({ x,y });
}
