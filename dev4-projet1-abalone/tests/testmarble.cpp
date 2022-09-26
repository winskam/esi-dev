#include<catch.hpp>
#include<marble.h>

namespace abalone { namespace test {

TEST_CASE("Test on a marble") {

    abalone::model::Player player = abalone::model::Player(1);
    abalone::model::Marble marble = abalone::model::Marble(player);

    SECTION("test the getter") {
        REQUIRE(marble.player()->id() == player.id());
    }

}

}}
