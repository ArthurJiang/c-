#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned int Factorial(unsigned int num) {
    return num <= 1 ? num : Factorial(num - 1) * num;
}

TEST_CASE("Factorial are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}
