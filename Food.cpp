#include "Food.hpp"

#include <iostream>

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
    // this isn't the best way to do randomness, but it doesn't really matter right now
    srand(time(0));
    pos.x = (rand() % NUM_CELLS) * CELL;
    //  + 8 is arbitrary. x and y would've been the same
    srand(time(0) + 8);
    pos.y = (rand() % NUM_CELLS) * CELL;

    food.setPosition(pos);
}
