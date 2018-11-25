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
