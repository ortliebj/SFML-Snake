#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Window.hpp>
#include <list>

#include "Food.hpp"

enum directions {right, left, up, down};

class Snake {
public:
    explicit Snake();

    // Draw snake to the window
    void drawSnake(sf::RenderWindow &w);

    // Check collisions with snake and edges of the window
    bool didCollide(sf::RenderWindow &w);

    // Check if snake ate the food block
    bool didEat(Food *f);

    // Advance snake in whatever direction it's moving. Adds a block to it's head
    void moveSnake();

    // Return the length of the snake
    //int getLength();  // don't need this now. Probably never will.

    // Adds a new block to the front of snake
    void pushFront();

    // Removes the tail of snake
    void popBack();

    // Update the direction snake is moving
    void changeDir(int d);

    // gets current direction of snake
    int getDir();

private:
    std::list<sf::RectangleShape> snake;
    int length;
    int dir;
};

#endif /* SNAKE_HPP */
