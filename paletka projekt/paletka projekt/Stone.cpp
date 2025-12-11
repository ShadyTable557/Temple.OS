//#include "stone.h"
//#include <iostream>
//
//Brick::Brick(float x, float y, float width, float height, int initialLives)
//    : x(x), y(y), width(width), height(height), lives(initialLives), isAlive(true)
//{
//    shape.setSize({ width, height });
//    shape.setOrigin({ width / 2, height / 2 });
//    shape.setPosition({ x, y });
//    updateColor();
//}
//
//void Brick::updateColor()
//{
//    if (lives == 3) {
//        shape.setFillColor(sf::Color::Red);
//    }
//    else if (lives == 2) {
//        shape.setFillColor(sf::Color::Yellow);
//    }
//    else if (lives == 1) {
//        shape.setFillColor(sf::Color::Green);
//    }
//    else {
//        // Brick is destroyed
//        isAlive = false;
//    }
//}
//
//void Brick::hit()
//{
//    if (isAlive) {
//        lives--;
//        if (lives <= 0) {
//            isAlive = false;
//        }
//        updateColor();
//    }
//}
//
//void Brick::draw(sf::RenderTarget& target)
//{
//    if (isAlive) {
//        target.draw(shape);
//    }
//}