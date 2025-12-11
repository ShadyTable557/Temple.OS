#pragma once
#include <SFML/Graphics.hpp>

class Cegla
{
private:
    sf::RectangleShape shape;
    float x, y;
    float width, height;
    int zycia;
    bool isAlive;

    void aktualizujKolor();

public:
    Cegla(float x, float y, float width, float height, int initialLives);

    void hit(); 
    void draw(sf::RenderTarget& target);

   
    float getLeft() const { return x - width / 2; }
    float getRight() const { return x + width / 2; }
    float getTop() const { return y - height / 2; }
    float getBottom() const { return y + height / 2; }

    bool getIsAlive() const { return isAlive; }
};