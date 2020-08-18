#include "Snake.hpp"
#include "Food.hpp"

#include <iostream>

enum directions {right, left, up, down};

Snake::Snake() {
    dir = directions::right;

    // initial snake size is 6, I guess
    for (int i = 0; i < 6; i++) {
        pushFront();
        length++;
    }
}

void Snake::moveSnake() {
    float dx = 0; // change in x position
    float dy = 0; // change in y position


    if (dir == directions::right) dx += CELL;
    if (dir == directions::left) dx -= CELL;
    if (dir == directions::up) dy -= CELL;
    if (dir == directions::down) dy += CELL;

    // current head position
    sf::Vector2f headPos(snake.front().getPosition());

    headPos.x += dx;
    headPos.y += dy;

    sf::RectangleShape head(sf::Vector2f(CELL, CELL));
    head.setPosition(headPos);
    head.setFillColor(sf::Color::Black);

    snake.push_front(head);
}

/*
 * Draw the whole snake to the window
 */
void Snake::drawSnake(sf::RenderWindow &w) {
    for (auto const& i : snake) {
        w.draw(i);
    }
}

/*
 * Returns the length of the snake. Same as score - 6 (initial size).
 */
int Snake::getLength() {
    return snake.size();
}

/*
 * Check if the snake ate. Returns true if it did.
 */
bool Snake::didEat(Food *f) {
    sf::Vector2f head = snake.front().getPosition();
    return head.x == f->getPos().x && head.y == f->getPos().y;
}

/*
 * Check collision between snake and itself, and snake and the walls.
 * Returns true on collision.
 */
bool Snake::didCollide(sf::RenderWindow &w) {
    for (auto it = std::next(snake.begin(), 1); it != snake.end(); ++it) {
        // Did snake collide with itself?
        if (it->getPosition() == snake.front().getPosition()) {
            return true;
        }
    }

    // these bottom two things can be combined

    // Did snake collide with the walls?
    if (snake.front().getPosition().x >= w.getSize().x || snake.front().getPosition().y >= w.getSize().y) {
        return true;
    }

    // Didn't collide
    return false;
}

/*
 * Add a new square to the front of the snake.
 */
void Snake::pushFront() {
    sf::RectangleShape rect(sf::Vector2f(CELL, CELL));
    sf::Vector2f currHead(snake.front().getPosition());

    float newX = currHead.x;
    float newY = currHead.y;

    if (dir == 0) newX += CELL;
    else if (dir == 1) newX -= CELL;
    else if (dir == 2) newY -= CELL;
    else if (dir == 3) newY += CELL;

    rect.setFillColor(sf::Color::Black);
    rect.setPosition(sf::Vector2f(newX, newY));
    snake.push_front(rect);

}

/*
 * Removes the tail of the snake.
 */
void Snake::popBack() {
    snake.pop_back();
}

/*
 * Set the member variable on change in direction.
 */
void Snake::changeDir(int d) {
    dir = d;
}