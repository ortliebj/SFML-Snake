#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"

class Game {
public:
    //Game();
    // Overloaded constructor - parameters: window, font, high score
    Game(sf::RenderWindow &w, sf::Font &f, int hs);

    // Start the game loop - returns score
    void start();

    // Returns the current score
    int getScore();

private:
    // Main loop with most of the game logic - returns score
    void gameLoop();

    // draws score to the window
    void drawScores();

    sf::RenderWindow &window;
    sf::Font font;
    Snake snake;
    Food food;

    int score;
    int highScore;
};

#endif /* GAME_HPP */
