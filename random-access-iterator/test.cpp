#include "tree.hpp"
#include <algorithm>
#include <doctest.h>

TEST_CASE("can iterate") {
    tree t{{{1, 2, 3}, 4, {5, 6, 7}}};
    int v = 1;
    for (int i : t) {
        CHECK(i == v++);
    }
    REQUIRE(v == 8);
}

TEST_CASE("operator[]") {
    tree t{{{1, 2, 3}, 4, {5, 6, 7}}};
    for (int i = 0; i < 7; ++i)
        CHECK(t[i] == i + 1);
}

TEST_CASE("throws exception on illegal access request") {
    tree t{{{1, 2, 3}, 4, {5, 6, {7, 8, {nil, 9, 10}}}}};
    CHECK_THROWS_AS((void)t.at(11), std::out_of_range);
    CHECK_THROWS_AS((void)t.at(-2), std::out_of_range);
}
