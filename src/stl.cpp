#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include "catch.hpp"

using namespace std;

TEST_CASE("Vector create", "[stl]") {
    vector<int> squares(100);

    for (size_t i = 0; i < squares.size(); i++) {
        squares[i] = i*i;
    }
    assert(squares[4] == 16);
    REQUIRE(squares.size() == 100);
    REQUIRE(squares[0] == 0);
    REQUIRE(squares[3] == 9);
}
