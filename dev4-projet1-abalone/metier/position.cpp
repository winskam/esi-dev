#include "position.h"
#include "algorithm"
#include <stdlib.h>

namespace abalone { namespace model {

Position::Position(int x, int y, int z) :
    x_ {x},
    y_ {y},
    z_ {z}
{}

bool Position::isPossiblePos(int size) {
    bool inside = x_ >= 0 && x_ < size && y_ >= 0 && y_ <  size && z_ >= 0 && z_ < size;
    int sum = (size/2)*3;
    bool possible = x_ + y_ + z_ == sum;
    return inside && possible;
}

int Position::distance(Position position2) {
    return std::max({abs(x_ - position2.x()), abs(y_ - position2.y()), abs(z_ - position2.z())});
}

Position operator+(const Position position1, const Position position2) {
    return Position(position1.x()+position2.x(), position1.y()+position2.y(), position1.z()+position2.z());
}

Position operator-(const Position position1, const Position position2) {
    return Position(position1.x()-position2.x(),position1.y()-position2.y(),position1.z()-position2.z());
}

bool operator==(const Position position1, const Position position2) {
    return position1.x()==position2.x() && position1.y()==position2.y() && position1.z()==position2.z();
}

Position abaToPosition(std::string string) {
    char charAba = string[0];
    int intAba = string[1] - 48;
    Position posBegin {Position(4,4,4)};

    if (charAba < 'J' &&  charAba >= 'A' && intAba > 0 && intAba < 10) {
        char charAbaBegin {'E'};
        int intAbaBegin {5};
        int charAbaDiff = charAbaBegin - charAba;
        int intAbaDiff = intAbaBegin - intAba;

        for (int i = 0; i < abs(charAbaDiff); i++) {
            if (charAbaDiff < 0) {
                posBegin = posBegin + Position(0,1,-1);
            } else if (charAbaDiff > 0){
                posBegin = posBegin + Position(0,-1,1);
            }
        }

        for (int i = 0; i < abs(intAbaDiff); i++) {
            if (intAbaDiff < 0) {
                posBegin = posBegin + Position(1,-1,0);
            } else if (intAbaDiff > 0) {
                posBegin = posBegin + Position(-1,1,0);
            }
        }

        if (!posBegin.isPossiblePos(9)) {
            throw std::invalid_argument("Position not on the board");
        }

    } else {
        throw std::invalid_argument("Position not on the board");
    }

    return posBegin;
}

}}
