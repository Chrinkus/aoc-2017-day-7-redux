#include <catch2/catch.hpp>

#include <find_diff.h>

#include <vector>
#include <string>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 2 arg find_diff

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

TEST_CASE("find_diff works regardless of diff position", "[find_diff]") {
    auto v1 = std::vector<int>{ 7, 3, 3 };
    auto v2 = std::vector<int>{ 3, 7, 3 };
    auto v3 = std::vector<int>{ 3, 3, 7 };

    auto it = find_diff(std::begin(v1), std::end(v1));
    REQUIRE(*it == 7);

    it = find_diff(std::begin(v2), std::end(v2));
    REQUIRE(*it == 7);

    it = find_diff(std::begin(v3), std::end(v3));
    REQUIRE(*it == 7);
}

TEST_CASE("find_diff works with std::string", "[find_diff]") {
    auto vs = std::vector<std::string>{ "foo", "foo", "foo", "bar" };
    auto it = find_diff(std::begin(vs), std::end(vs));
    REQUIRE(*it == "bar");
}

TEST_CASE("find_diff returns last when all values the same", "[find_diff]") {
    auto vc = std::vector<char>{ 'c', 'c', 'c', 'c', 'c', 'c' };
    auto it = find_diff(std::begin(vc), std::end(vc));
    REQUIRE(it == std::end(vc));
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
// 3 arg find_diff

struct Person {
    Person(const std::string& n, int a, int w)
        : name{n}, age{a}, weight{w} { }
    std::string name;
    int age = 0;
    int weight = 0;
};

bool cmp_weight(const Person& a, const Person& b)
{
    return a.weight == b.weight;
}

TEST_CASE("find_diff binary op overload works", "[find_diff]") {
    auto vp = std::vector<Person> {
        Person{ "Mary", 36, 210 }, Person{ "Chris", 39, 210 },
        Person{ "Mark", 22, 210 }, Person{ "Kyle", 24, 215 }
    };
    auto it = find_diff(std::begin(vp), std::end(vp), cmp_weight);
    REQUIRE(it != std::end(vp));
    REQUIRE(it->name == "Kyle");
}
