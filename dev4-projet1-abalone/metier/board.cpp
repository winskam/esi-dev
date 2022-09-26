#include "board.h"
#include <array>

namespace abalone { namespace model {

Board::Board(Player & playerBlack, Player &playerWhite) :
    marbles_ {}
{
    for (auto x = 0; x < size(); x++) {
        for (auto y = 0; y < size(); y++) {
            for (auto z = 0; z < size(); z++) {
                if (isPosPossible(Position(x,y,z))) {
                    if ((z == 0 && x >= 4 && y >= 4)
                            || (z == 1 && x >= 3 && y >= 3)
                            || (z == 2 && x > 3 && x < 7 && y > 3 && y < 7)) {
                        marbles_[x][y][z] = new Marble(playerWhite);
                    } else if ((z == 8 && x < 5 && y < 5)
                               || (z == 7 && x < 6 && y < 6)
                               || (z == 6 && x < 5 && x > 1 && y > 1 && y < 5)) {
                        marbles_[x][y][z] = new Marble(playerBlack);
                    }
                }
            }
        }
    }
}

Marble * Board::marbleAtPosition(Position position) {
    if (isPosPossible(position)) {
        return (marbles_[position.x()][position.y()][position.z()]) ? *marbles_[position.x()][position.y()][position.z()]: NULL;
    } else {
        return NULL;
    }
}

Player * Board::playerAtPosition(Position position) {
    if (marbleAtPosition(position)) {
        return marbleAtPosition(position)->player();
    } else {
        return NULL;
    }
}

void Board::deleteAtPosition(Position position) {
        delete (*marbles_[position.x()][position.y()][position.z()]);
        *marbles_[position.x()][position.y()][position.z()] = NULL;
}

bool Board::isPosPossible(Position position) {
    return position.isPossiblePos(size());
}

void Board::changePosition(Position posBegin, Position posEnd) {
    if (isPosPossible(posEnd)) {
        marbles_[posEnd.x()][posEnd.y()][posEnd.z()] = marbles_[posBegin.x()][posBegin.y()][posBegin.z()];
        *marbles_[posBegin.x()][posBegin.y()][posBegin.z()] = NULL;
    } else {
        marbleAtPosition(posBegin)->player()->deleteMarble();
        deleteAtPosition(posBegin);
    }
}


}}
