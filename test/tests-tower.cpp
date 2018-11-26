#include <catch2/catch.hpp>

#include <tower.h>

#include <sstream>

SCENARIO("Tower_factory takes input and creates Towers", "[Tower_factory]") {

    /* Had an issue here where I only provided the original line (qwert..) as
     * input to the stringstream. This created a data vector of size 1 but
     * when the tower was created four programs were created. Since the tower's
     * vector was sized off of the data a reallocation occured invalidating
     * the pointer data and causing segfaults.
     */

    std::stringstream small_ss;
    small_ss << "qwert (37) -> asdfg, zxcvb, yuiop\n"
             << "zxcvb (17)\n"
             << "asdfg (17)\n"
             << "yuiop (17)\n";

    std::stringstream med_ss;
    med_ss << "pbga (66)\n"
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

    GIVEN("A Tower_factory with balanced data") {
        auto tf = Tower_factory{small_ss};

        REQUIRE(tf.data_size() == 4);

        WHEN("A balanced Tower is created") {
            auto t = tf.create_tower();

            THEN("The Tower size is the same as factory data") {
                REQUIRE(t.tower_size() == tf.data_size());
            }
            THEN("The base is correctly set") {
                REQUIRE(t.get_base()->get_name() == "qwert");
            }
            THEN("The Tower is found to be balanced") {
                REQUIRE(t.get_base()->is_balanced() == true);
            }
        }
    }

    GIVEN("A Tower_factory with unbalanced data") {
        auto tf = Tower_factory{med_ss};

        REQUIRE(tf.data_size() == 13);

        WHEN("An unbalanced Tower is created") {
            auto t = tf.create_tower();

            THEN("The Tower size is the same as factory data") {
                REQUIRE(t.tower_size() == tf.data_size());
            }
            THEN("The base is correctly set") {
                REQUIRE(t.get_base()->get_name() == "tknk");
            }
            THEN("The above_weight is correctly calculated") {
                REQUIRE(t.get_base()->get_above_weight() == 737);
            }
            THEN("The tower is found to be unbalanced") {
                REQUIRE(t.get_base()->is_balanced() == false);
            }
        }
    }
}
