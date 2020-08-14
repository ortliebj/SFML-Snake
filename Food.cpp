
#include <random>

#include "Food.hpp"

Food::Food() {
    food.setSize(sf::Vector2f (CELL, CELL));
    food.setFillColor(sf::Color::Green);
    randomizePos();
}

sf::RectangleShape Food::getFood() {
    return food;
}

sf::Vector2f Food::getPos() {
    return pos;
}

void Food::drawFood(sf::RenderWindow &w) {
    w.draw(food);
}

void Food::randomizePos() {
    srand(time(NULL));
    pos.x = (rand() % NUM_CELLS + 1) * CELL;
    srand(time(NULL));
    pos.y = (rand() % NUM_CELLS + 1) * CELL;

    food.setPosition(pos);
}
