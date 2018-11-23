#include <catch2/catch.hpp>

#include <tower.h>

#include <sstream>


TEST_CASE("Tower_factory populates table from input", "[Tower_factory]") {

    std::istringstream iss {"qwert (37) -> asdfg, zxcvb, yuiop"};
    Tower_factory tf {iss};

    REQUIRE(tf.data_size() == 1);

    auto t = tf.create_tower();
    REQUIRE(t.tower_size() == 4);
}
