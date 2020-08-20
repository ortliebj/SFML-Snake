#include "GameController.hpp"

//GameController::GameController() {

//}

GameController::GameController(sf::RenderWindow &w)
    : window(w) {
    isPlaying = false;
    highScore = 0;
    // Load arial font - only supports macos path right now
    font.loadFromFile("/Library/Fonts/Arial Unicode.ttf");
}

void GameController::newGame() {
    Game game(window, font, highScore);
    game.start();

    // update highscore if needed
    if (game.getScore() > highScore) {
        highScore = game.getScore();
    }

    isPlaying = false;
}

void GameController::gameOver() {
    // recreate window
    window.create(sf::VideoMode(CELL*NUM_CELLS, CELL*NUM_CELLS), "Snake");

    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over.\nPress 'Enter' to start a new game");
    gameOverText.setCharacterSize(40);
    gameOverText.setFillColor(sf::Color::Black);

    // Draw the text
    window.clear(sf::Color::White);
    window.draw(gameOverText);
    window.display();

    while (window.isOpen() && isPlaying == false) {
        // poll events
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Enter key pressed
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                isPlaying = true;
            }
        }
    }
}

bool GameController::gameIsActive() {
    return isPlaying;
}