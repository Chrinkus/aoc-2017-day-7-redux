#include <catch2/catch.hpp>

#include <tower.h>

#include <sstream>


TEST_CASE("Tower_factory populates table from min input", "[Tower_factory]") {

    std::istringstream iss {"qwert (37) -> asdfg, zxcvb, yuiop"};
    Tower_factory tf {iss};

    REQUIRE(tf.data_size() == 1);

    auto t = tf.create_tower();
    REQUIRE(t.tower_size() == 4);
}

TEST_CASE("Tower_factory populates table from test input", "[Tower_factory]") {

    std::stringstream ss;
    ss << "pbga (66)\n"
       << "xhth (57)\n"
       << "ebii (61)\n"
       << "havc (66)\n"
       << "ktlj (57)\n"
       << "fwft (72) -> ktlj, cntj, xhth\n"
       << "qoyq (66)\n"
       << "padx (45) -> pbga, havc, qoyq\n"
       << "tknk (41) -> ugml, padx, fwft\n"
       << "jptl (61)\n"
       << "ugml (68) -> gyxo, ebii, jptl\n"
       << "gyxo (61)\n"
       << "cntj (57)\n";

    Tower_factory tf {ss};

    REQUIRE(tf.data_size() == 13);

    auto t = tf.create_tower();
    REQUIRE(t.tower_size() == 13);
    REQUIRE(t.get_base()->get_name() == "tknk");
    REQUIRE(t.get_base()->num_children() == 3);
    REQUIRE(t.get_base()->get_above_weight() == 737);
}
