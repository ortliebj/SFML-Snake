
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Window.hpp>
#include <list>

#include "Food.hpp"

class Snake {
public:
    explicit Snake();
    //~Snake();
    void drawSnake(sf::RenderWindow &w);
    bool didCollide(sf::RenderWindow &w);
    bool didEat(Food *f);
    void moveSnake();
    int getLength();
    void pushFront();
    void popBack();
    void changeDir(int d);

private:
    std::list<sf::RectangleShape> snake;
    int length;
    int dir;


};

#endif /* SNAKE_HPP */
