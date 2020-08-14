// #include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

#include <chrono>
#include <thread>

#include "Snake.hpp"
//#include "Food.hpp"


int main(int, char const**) {
    float x = 0; // current x position
    float y = 0; // current y position

    //enum directions {right, left, up, down};

    sf::RenderWindow window(sf::VideoMode(CELL * NUM_CELLS, CELL * NUM_CELLS), "Snake", sf::Style::Default);
    window.setKeyRepeatEnabled(false);
    //window.setFramerateLimit(30);

    Snake snake;
    Food food;

    // Keep the program going as long as the window is open
    while (window.isOpen()) {

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


    return 0;
}
