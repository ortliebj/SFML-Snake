#include "GameController.hpp"

int main(int, char const**) {

    sf::RenderWindow window(sf::VideoMode(CELL*NUM_CELLS, CELL*NUM_CELLS), "Snake");

    GameController controller(window);

    while (window.isOpen()) {
        sf::Event event;
        // Check window closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (controller.gameIsActive()) {
            controller.newGame();
        }
        else {
            controller.gameOver();
        }
    }


    return 0;
}
