#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "class.hpp"
using namespace std;

IntCell::IntCell(int value) : m_storedValue(value) {

}

int IntCell::read() const {
    return m_storedValue;
}

void IntCell::write(int value) {
    m_storedValue = value;
}

TEST_CASE("Class created", "[class]") {
    IntCell m1(1);
    REQUIRE(m1.read() == 1);
    m1.write(2);
    REQUIRE(m1.read() == 2);

    IntCell* pm2 = NULL;
    REQUIRE(pm2 == NULL);
    pm2 = new IntCell(2);
    REQUIRE(pm2->read() == 2);
    delete pm2;
}
