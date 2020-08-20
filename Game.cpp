#include <string> // to_string

#include "Game.hpp"
#include "Snake.hpp"

Game::Game(sf::RenderWindow &w, sf::Font &f, int hs)
        : window(w), font(f), highScore(hs) {
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(10);

    score = 0;
}

void Game::start() {
    gameLoop();
}

int Game::getScore() {
    return score;
}

void Game::gameLoop() {
    // Keep the game loop going as long as snake is alive
    while (window.isOpen() ){//&& isAlive) {
        // check all of the window's events that were triggered since the last iteration
        sf::Event event;
        while (window.pollEvent(event)) {
            // close the window on close request
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                // set new direction - prevents moving in the opposite direction (can't move left if you're moving right)
                if (event.key.code == sf::Keyboard::Right && snake.getDir() != directions::left) snake.changeDir(directions::right);
                else if (event.key.code == sf::Keyboard::Left && snake.getDir() != directions::right) snake.changeDir(directions::left);
                else if (event.key.code == sf::Keyboard::Up && snake.getDir() != directions::down) snake.changeDir(directions::up);
                else if (event.key.code == sf::Keyboard::Down && snake.getDir() != directions::up) snake.changeDir(directions::down);
            }
        } // inner while

        window.clear(sf::Color::White);

        food.drawFood(window);

        snake.moveSnake();

        // Check collisions
        if (snake.didCollide(window)) {
            // Exit game loop
            return;
        }

        // Check if snake ate
        if (snake.didEat(&food)) {
            ++score;
            food.randomizePos();
            snake.pushFront();
        } else {
            snake.popBack();
        }

        drawScores();
        snake.drawSnake(window);

        window.display();

    } // outer while
}

void Game::drawScores() {
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("High Score: " + std::to_string(highScore) + "\nScore: " + std::to_string(score));
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Black);
    window.draw(scoreText);
}