#include<player.h>
#include<catch.hpp>

namespace abalone { namespace test {

TEST_CASE("Test on the player") {

    abalone::model::Player player = abalone::model::Player(2);

    SECTION("Test getters") {
       REQUIRE(player.nbMarbles() == 14);
       REQUIRE(player.id() == 2);
    }

    SECTION("Test delete") {
       player.deleteMarble();
       REQUIRE(player.nbMarbles() == 13);
    }

}

}}
