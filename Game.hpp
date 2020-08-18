
#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"

class Game {
public:
    //Game();
    Game(sf::RenderWindow &w);
    // Start the game loop
    void start();

private:
    // Main loop with most of the game logic
    void gameLoop();

    sf::RenderWindow &window;
    Snake snake;
    Food food;

    bool isAlive;

};


#endif /* GAME_HPP */
