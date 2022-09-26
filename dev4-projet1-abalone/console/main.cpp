#include <iostream>
#include "game.h"
#include "observable.h"
#include "view.h"
#include <stdexcept>

int main() {

    abalone::model::Game game = abalone::model::Game();
    abalone::view::View view = abalone::view::View(&game);

    while (!game.checkWon()) {
        bool readSuccess { false };
        while (!readSuccess) {
            std::cout << "Please enter a movement in ABA-Pro : ";
            try {
                std::string string;
                std::getline(std::cin, string);
                game.stringToMovement(string);
                readSuccess = true;
            }
            catch (const std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    game.cleanBoard();

}
