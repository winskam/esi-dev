#include<position.h>
#include<catch.hpp>

namespace abalone { namespace test {


TEST_CASE("Test on position") {

    abalone::model::Position position1 = abalone::model::Position(4,4,4);
    abalone::model::Position position2 = abalone::model::Position(4,6,4);

    SECTION("Test getters") {
       REQUIRE(position1.x() == 4);
       REQUIRE(position1.y() == 4);
       REQUIRE(position1.z() == 4);
    }

    SECTION("Test isPossible") {
       REQUIRE(position1.isPossiblePos(9));
       REQUIRE_FALSE(position2.isPossiblePos(9));
    }

    SECTION("Test distance") {
       REQUIRE(position1.distance(abalone::model::Position(6,4,2)) == 2);
    }

    SECTION("Test - operator") {
        abalone::model::Position positionResult = position1 - abalone::model::Position(1,2,3);
        REQUIRE(positionResult.x()== 3);
        REQUIRE(positionResult.y()== 2);
        REQUIRE(positionResult.z()== 1);
    }

    SECTION("Test + operator") {
        abalone::model::Position positionResult = position1 + abalone::model::Position(1,2,3);
        REQUIRE(positionResult.x()== 5);
        REQUIRE(positionResult.y()== 6);
        REQUIRE(positionResult.z()== 7);
    }

    SECTION("Test abaToPos") {
        abalone::model::Position positionResult = abalone::model::abaToPosition("A5");
        REQUIRE(positionResult.x()== 4);
        REQUIRE(positionResult.y()== 0);
        REQUIRE(positionResult.z()== 8);
    }

    SECTION("Test abaToPos not possible") {
        REQUIRE_THROWS(abalone::model::abaToPosition("X5"));
         REQUIRE_THROWS(abalone::model::abaToPosition("A9"));
    }

}

}}
