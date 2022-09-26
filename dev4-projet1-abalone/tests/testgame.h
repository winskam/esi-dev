#ifndef TESTGAME_H
#define TESTGAME_H
#include "game.h"

namespace abalone { namespace test {

class TestGame: public model::Game {

public :

    model::Board getBoard();

};}

model::Board abalone::test::TestGame::getBoard() {
    return model::Game::getBoard();
}

}

#endif // TESTGAME_H
