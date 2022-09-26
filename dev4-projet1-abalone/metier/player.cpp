#include "player.h"
#include <stdexcept>

namespace abalone { namespace model {

Player::Player(int id) :
    id_ {(id == 1 || id == 2) ? id : throw std::invalid_argument("Player must be 1 or 2.")},
    nbMarbles_ {14}
{}

void Player::deleteMarble() {
    nbMarbles_ -= 1;
}

         Player& Player::operator= (const Player& f) {
        id_ = f.id();
        nbMarbles_ = f.nbMarbles_;
        return *this;
}

}}
