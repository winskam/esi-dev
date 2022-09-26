#include "game.h"
#include "board.h"
#include <list>
#include <stdexcept>

namespace abalone { namespace model {

Game::Game():
    list_observer_ {},
    playerWhite_ {Player(2)},
    playerBlack_ {Player(1)},
    playerTurn_ {&playerBlack()},
    gameBoard_ {Board(playerBlack(), playerWhite())}
{}

bool Game::checkWon() {
    return playerWhite().nbMarbles() < 9 || playerBlack().nbMarbles() < 9;
}

void Game::changeTurn() {
    setTurn((playerTurn()->id() == 2) ? playerBlack() : playerWhite());
}

void Game::setTurn(Player &player) {
    playerTurn_ = &player;
}

void Game::stringToMovement(std::string string) {
    if (string.size() != 6 && string.size() != 4) {
        throw std::invalid_argument("Not in ABA-pro !");
    }

    if (string.size() == 4) {
        Position position1 = abaToPosition(string.substr(0,2));
        Position position2 = abaToPosition(string.substr(2,2));
        makeMove(position1,position2);
    } else {
        Position position1 = abaToPosition(string.substr(0,2));
        Position position2 = abaToPosition(string.substr(2,2));
        Position position3 = abaToPosition(string.substr(4,2));
        makeMove(position1,position2,position3);
    }
}

bool Game::isMovePossible(Position posBegin) {
    if (gameBoard_.playerAtPosition(posBegin) &&
            gameBoard_.playerAtPosition(posBegin)->id() == playerTurn()->id()) {
        return true;
    } else {
        throw std::invalid_argument("Please select your own marbles");
    }
}

bool Game::isMovePossible(Position posBeginFirst, Position posBeginLast) {
    if (gameBoard_.playerAtPosition(posBeginFirst) &&
            gameBoard_.playerAtPosition(posBeginFirst)->id() == playerTurn()->id() &&
            gameBoard_.playerAtPosition(posBeginLast) &&
            gameBoard_.playerAtPosition(posBeginLast)->id() == playerTurn()->id()) {
        if (posBeginFirst.distance(posBeginLast) == 2) {
            Position middle = Position((posBeginFirst.x()+posBeginLast.x()) / 2,
                                       (posBeginFirst.y()+posBeginLast.y()) / 2,
                                       (posBeginFirst.z()+posBeginLast.z()) / 2);
            return (gameBoard_.playerAtPosition(middle) &&
                    gameBoard_.playerAtPosition(middle)->id() == playerTurn()->id())
                    ?
                        true:
                        throw std::invalid_argument("Please select your own marbles");
        } else {
            return true;
        }
    } else {
        throw std::invalid_argument("Please select your own marbles");
    }
}

void Game::makeMove(Position posBegin, Position posEnd) {
    if (isMovePossible(posBegin) && posBegin.distance(posEnd) == 1) {
        Position direction =  posEnd - posBegin;
        Position nextPosition = posEnd;
        Position posForPlayer = posEnd;
        auto i = 0;
        auto j = 0;

        while (gameBoard_.playerAtPosition(nextPosition))  {
            if (gameBoard_.playerAtPosition(nextPosition)->id() != playerTurn()->id()) {
                if (j==0) {
                    posForPlayer = nextPosition;
                }
                j++;
            } else {
                i++;
            }
            nextPosition = nextPosition + direction;
        }

        if (i<3 && j==0) {
            gameBoard_.changePosition(posBegin,nextPosition);
            changeTurn();
            notifyObservers();
        } else if (j<=i && i < 3) {
            gameBoard_.changePosition(posForPlayer,nextPosition);
            gameBoard_.changePosition(posBegin,posForPlayer);
            changeTurn();
            notifyObservers();
        } else throw std::invalid_argument("Illegal movement !");
    } else throw std::invalid_argument("Illegal movement !");
}

void Game::makeMove(Position posBeginFirst, Position posBeginLast, Position posEndFirst) {
    if (isMovePossible(posBeginFirst,posBeginLast)) {
        Position movement = posBeginFirst - posEndFirst;
        if (posBeginFirst.distance(posBeginLast) == 1 && posBeginFirst.distance(posEndFirst) == 1) {
            if (!gameBoard_.marbleAtPosition(posEndFirst) &&
                    !gameBoard_.marbleAtPosition(posBeginLast-movement)) {
                gameBoard_.changePosition(posBeginFirst,posEndFirst);
                gameBoard_.changePosition(posBeginLast,posBeginLast-movement);
                changeTurn();
                notifyObservers();
            }
        } else if (posBeginFirst.distance(posBeginLast) == 2&& posBeginFirst.distance(posEndFirst) == 1) {
            Position middle = Position((posBeginFirst.x()+posBeginLast.x()) / 2,
                                       (posBeginFirst.y()+posBeginLast.y()) / 2,
                                       (posBeginFirst.z()+posBeginLast.z()) / 2);
            if (!gameBoard_.marbleAtPosition(posEndFirst) &&
                    !gameBoard_.marbleAtPosition(posBeginFirst-movement) &&
                    !gameBoard_.marbleAtPosition(middle-movement)) {
                gameBoard_.changePosition(posBeginFirst,posEndFirst);
                gameBoard_.changePosition(middle,middle-movement);
                gameBoard_.changePosition(posBeginLast,posBeginLast-movement);
                changeTurn();
                notifyObservers();
            }
        } else {
            throw std::invalid_argument("Positions are not in reglementary distance of each other");
        }
    }
}

void Game::cleanBoard() {
    if (checkWon()) {
        for (auto x = 0; x<gameBoard_.size(); x++) {
            for (auto y = 0; y < gameBoard_.size(); y++) {
                for (auto z = 0; z < gameBoard_.size(); z++) {
                    Position posToDelete = Position(x,y,z);
                    if (gameBoard_.marbleAtPosition(posToDelete)) {
                        gameBoard_.deleteAtPosition(posToDelete);
                    }
                }
            }
        }
    }
}

void Game::reset() {
    if(checkWon()) {
        playerBlack_ = Player(1);
        playerWhite_ = Player(2);
        playerTurn_  =&playerBlack();
        gameBoard_ = Board(playerBlack(), playerWhite());
        notifyObservers();
    }
}

}}
