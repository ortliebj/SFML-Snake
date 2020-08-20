#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Game.hpp"

class GameController {
public:
 //   GameController();
    GameController(sf::RenderWindow &w);

    // Start a new game
    void newGame();

    // Show the "game over" screen
    void gameOver();

    // returns 'isPlaying' - whether or not a game is active
    bool gameIsActive();

private:
    sf::RenderWindow &window;
    sf::Font font;

    bool isPlaying;
    int highScore;
};

#endif /* GAMECONTROLLER_HPP */
