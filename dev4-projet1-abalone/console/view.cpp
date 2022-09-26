#include "view.h"
#include "game.h"
#include <iostream>

namespace abalone { namespace view {

View::View(model::Game * subject) :
    subject_ {subject}
{
    subject_->registerObserver(this);
    update(subject_);
}

View::~View() {
    subject_->unregisterObserver(this);
}

void View::printWin() {
    if (subject_->playerBlack().nbMarbles() == 8) {
        std::cout << "Congrats ! Player o won!!" << std::endl;
    } else if (subject_->playerWhite().nbMarbles() == 8) {
        std::cout << "Congrats ! Player x won!!" << std::endl;
    }
}

void View::printGame(){
    std::string output = "";
    std::cout << "         __________\n";
    for (auto z = 0; z < subject_->getBoard().size(); z++) {
        for (auto y = subject_->getBoard().size() - 1; y >= 0; y--) {
            std::cout << "";
            for (auto x = 0; x < subject_->getBoard().size(); x++) {
                abalone::model::Position position = abalone::model::Position(x,y,z);
                if (subject_->getBoard().isPosPossible(position)) {
                    if (x == 4 && y == 8 && z == 0) {
                        std::cout << "     I--/";
                    } else if (x == 3 && y == 8 && z == 1) {
                        std::cout << "    H--/";
                    } else if (x == 2 && y == 8 && z == 2) {
                        std::cout << "   G--/";
                    } else if (x == 1 && y == 8 && z == 3) {
                        std::cout << "  F--/";
                    } else if (x == 0 && y == 8 && z == 4) {
                        std::cout << " E--<";
                    } else if (x == 0 && y == 7 && z == 5) {
                        std::cout << "  D--\\";
                    } else if (x == 0 && y == 6 && z == 6) {
                        std::cout << "   C--\\";
                    } else if (x == 0 && y == 5 && z == 7) {
                        std::cout << "    B--\\";
                    } else if (x == 0 && y == 4 && z == 8) {
                        std::cout << "     A--\\";
                    }

                    if (subject_->getBoard().playerAtPosition(position)) {
                        std::cout << ((subject_->getBoard().playerAtPosition(position)->id() == 1) ? "o ":"x ");
                    } else {
                        std::cout <<  ". ";
                    }

                    if ((x == 8 || y == 0) && z < 4) {
                        std::cout <<  "\\ \n";
                    } else if (x == 8 || y == 0) {
                        switch (z) {
                        case 5 :
                            std::cout <<  "/\\ \n";
                            break;
                        case 6 :
                            std::cout <<  "/\\ 9 \n";
                            break;
                        case 7 :
                            std::cout <<  "/\\ 8 \n";
                            break;
                        case 8 :
                            std::cout <<  "/\\ 7 \n";
                            break;
                        default :
                            std::cout <<  ">\n";
                        }
                    }
                }
            }
        }
    }

    std::cout << "         -\\-\\-\\-\\-\\  6 \n           1 2 3 4 5" << std::endl;
}

void View::update(const Observable * subject) {
    if (subject != subject_) return;
    std::string string = "Player turn: ";
    std::string string2 = (subject_->playerTurn()->id() == 1) ? "o" : "x";
    std::cout << string << string2 << std::endl;
    printGame();
    printWin();
}

}}
