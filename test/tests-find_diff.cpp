#include <catch2/catch.hpp>

#include "../src/find_diff.h"
#include <vector>

TEST_CASE("find_diff returns last when range too small", "[find_diff]") {
    auto vi = std::vector<int>{};

    REQUIRE(find_diff(std::begin(vi), std::end(vi)) == std::end(vi));

    vi.push_back(3);
    vi.push_back(3);

    REQUIRE(find_diff(std::begin(vi), std::end(vi)) == std::end(vi));
}

TEST_CASE("find_diff returns iterator to different value", "[find_diff]") {
    auto vi = std::vector<int>{ 3, 3, 3, 7, 3 };
    auto it = find_diff(std::begin(vi), std::end(vi));

    REQUIRE(*it == 7);
}
