#include <chrono> // milliseconds
#include <thread> // sleep

#include "Game.hpp"
#include "Snake.hpp"
//#include "Food.hpp"
/*
Game::Game() {
    window.create(sf::VideoMode(CELL*NUM_CELLS, CELL*NUM_CELLS), "Snake", sf::Style::Default);
    isAlive = true;
}
*/
Game::Game(sf::RenderWindow &w)
        : window(w) {
    //window.create(sf::VideoMode(CELL*NUM_CELLS, CELL*NUM_CELLS), "Snake", sf::Style::Default);
    window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(30);

    isAlive = true;
}

void Game::start() {
    isAlive = true;
    gameLoop();
}

void Game::gameLoop() {
    // Keep the game loop going as long as snake is alive
    while (window.isOpen() && isAlive) {
        // check all of the window's events that were triggered since the last iteration
        sf::Event event;
        while (window.pollEvent(event)) {
            // close the window on close request
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                // set new direction
                if (event.key.code == sf::Keyboard::Right)     snake.changeDir(0);
                else if (event.key.code == sf::Keyboard::Left) snake.changeDir(1);
                else if (event.key.code == sf::Keyboard::Up)   snake.changeDir(2);
                else if (event.key.code == sf::Keyboard::Down) snake.changeDir(3);
            }
        } // inner while

        window.clear(sf::Color::White);

        food.drawFood(window);

        snake.moveSnake();

        // Check collisions
        if (snake.didCollide(window)) {
            //gameOver();
            isAlive = false;
            //return;
        }

        // Check if snake ate
        if (snake.didEat(&food)) {
            food.randomizePos();
            snake.pushFront();
        } else {
            snake.popBack();
        }


        snake.drawSnake(window);

        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } // outer while
}
