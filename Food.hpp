
#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics.hpp>

const int CELL = 30;  // Width and height of each "cell" on the board
const int NUM_CELLS = 40;  // Number of "cells" in width and height of the board

class Food {
public:
    Food();
    void randomizePos();
    sf::Vector2f getPos();
    sf::RectangleShape getFood();
    void drawFood(sf::RenderWindow &w);

private:
    sf::RectangleShape food;
    sf::Vector2f pos;

};

#endif /* FOOD_HPP */
