#include <catch2/catch.hpp>

#include <program.h>

#include <string>

TEST_CASE("Program_data constructs from expected format", "[Program_data]") {

    auto s_short = std::string{"qwert (37)"};
    auto pd_short = Program_data{s_short};

    REQUIRE(pd_short.name == "qwert");
    REQUIRE(pd_short.weight == 37);
    REQUIRE(pd_short.child_names.size() == 0);

    auto s_long = std::string{"wasdf (53) -> yuiop, ghjkl, vbnmc"};
    auto pd_long = Program_data{s_long};

    REQUIRE(pd_long.name == "wasdf");
    REQUIRE(pd_long.weight == 53);
    REQUIRE(pd_long.child_names.size() == 3);
}

TEST_CASE("Program constructs from expected input", "[Program]") {

    auto s_short = std::string{"qwert (37)"};
    auto pd_short = Program_data{s_short};
    auto p_short = Program{pd_short};

    REQUIRE(p_short.get_name() == "qwert");
    REQUIRE(p_short.get_weight() == 37);
    REQUIRE(p_short.get_parent() == nullptr);
    REQUIRE(p_short.get_children().size() == 0);

    auto s_long = std::string{"wasdf (53) -> yuiop, ghjkl, vbnmc"};
    auto pd_long = Program_data{s_long};
    auto p_long = Program{pd_long};

    REQUIRE(p_long.get_name() == "wasdf");
    REQUIRE(p_long.get_weight() == 53);
    REQUIRE(p_long.get_parent() == nullptr);
    REQUIRE(p_short.get_children().size() == 0);
}

TEST_CASE("Program modifying functions work as expected", "[Program]") {

    auto pd_base    = Program_data{"flack (9) -> quimm, larek, chowo"};
    auto pd_one     = Program_data{"quimm (3) -> pawld, trimm"};
    auto pd_two     = Program_data{"larek (4)"};
    auto pd_three   = Program_data{"chowo (3)"};
    auto pd_four    = Program_data{"pawld (7)"};
    auto pd_five    = Program_data{"trimm (7)"};

    auto base    = Program{pd_base};
    auto c_one   = Program{pd_one};
    auto c_two   = Program{pd_two};
    auto c_three = Program{pd_three};
    auto c_four  = Program{pd_four};
    auto c_five  = Program{pd_five};

    REQUIRE(base.num_children() == 0);

    base.add_child(&c_one);
    base.add_child(&c_two);
    base.add_child(&c_three);
    c_one.add_child(&c_four);
    c_one.add_child(&c_five);

    SECTION("add child adds to children and sets their parent") {
        REQUIRE(base.num_children() == 3);
        REQUIRE(c_one.get_parent() == &base);
        REQUIRE(c_five.get_parent() == &c_one);
    }

    REQUIRE(base.get_above_weight() == 0);

    base.calc_above_weight();

    SECTION("calc_above_weight works as expected") {
        REQUIRE(base.get_above_weight() == 24);
    }
}
