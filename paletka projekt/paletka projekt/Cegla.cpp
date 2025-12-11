#include "ceg³a.h"
#include <SFML/Graphics.hpp>

Cegla::Cegla(float x, float y, float width, float height, int initialLives)
    : x(x), y(y), width(width), height(height), zycia(initialLives), isAlive(true)
{
    shape.setSize({ width, height });
    shape.setOrigin({ width / 2, height / 2 });
    shape.setPosition({ x, y });
    aktualizujKolor();
}

void Cegla::aktualizujKolor()
{
    if (zycia == 3) 
    {
        shape.setFillColor(sf::Color::Red);
    }
    else if (zycia == 2) 
    {
        shape.setFillColor(sf::Color::Yellow);
    }
    else if (zycia == 1) 
    {
        shape.setFillColor(sf::Color::Green);
    }
    else 
    {
       
        isAlive = false;
    }
}

void Cegla::hit()
{
    if (isAlive) {
        zycia--;
        if (zycia <= 0) {
            isAlive = false;
        }
        aktualizujKolor();
    }
}

void Cegla::draw(sf::RenderTarget& target)
{
    if (isAlive) {
        target.draw(shape);
    }
}