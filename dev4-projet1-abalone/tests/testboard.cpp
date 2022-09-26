#include<game.h>
#include<catch.hpp>

TEST_CASE("Test some moves on the board") {

    abalone::model::Player player1 = abalone::model::Player(1);
    abalone::model::Player player2 = abalone::model::Player(2);
    abalone::model::Board board = abalone::model::Board(player1,player2);

    SECTION("Simple Movement") {
        board.changePosition(abalone::model::Position(3,3,6), abalone::model::Position(4,4,4));
        REQUIRE_FALSE(board.marbleAtPosition(abalone::model::Position(3,3,6)));
        REQUIRE(board.playerAtPosition(abalone::model::Position(4,4,4))->id() == 1);
    }

    SECTION("Move outside the board") {
        board.changePosition(abalone::model::Position(3,3,6), abalone::model::Position(4,4,9));
        REQUIRE_FALSE(board.marbleAtPosition(abalone::model::Position(3,3,6)));
        REQUIRE(player1.nbMarbles() == 13);
    }

    SECTION("Is position possible") {
        REQUIRE(board.isPosPossible(abalone::model::Position(4,4,4)));
    }

    SECTION("Is position not possible") {
        REQUIRE_FALSE(board.isPosPossible(abalone::model::Position(7,2,4)));
    }

    SECTION("Check for marble at a certain position") {
        REQUIRE(board.marbleAtPosition(abalone::model::Position(3,3,6))->player()->id() == 1);
    }

    SECTION("Check at a position without marble") {
        REQUIRE_FALSE(board.marbleAtPosition(abalone::model::Position(4,4,4)));
    }

    SECTION("Check for marble at impossible position") {
        REQUIRE_FALSE(board.marbleAtPosition(abalone::model::Position(7,7,7)));
    }

    SECTION("Check for player at position") {
        REQUIRE(board.playerAtPosition(abalone::model::Position(3,3,6))->id() == 1);
    }

    SECTION("Check for position at position without player") {
        REQUIRE_FALSE(board.playerAtPosition(abalone::model::Position(4,4,4)));
    }

    SECTION("checks if delete works") {
       board.deleteAtPosition(abalone::model::Position(3,3,6));
       REQUIRE_FALSE(board.marbleAtPosition(abalone::model::Position(3,3,6)));
    }

}
