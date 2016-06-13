#define CATCH_CONFIG_MAIN

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "string.h"
#include "catch.hpp"

using namespace std;

// Function template
// Comparable objs need provide operator < and operator =


template <typename Obj, typename Cmp>
const Obj& findMax(const vector<Obj>& arr, Cmp less) {
    int maxIndex = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (less(arr[maxIndex], arr[i])) {
            maxIndex = i;
        }
    }

    return arr[maxIndex];
}

template <typename Obj>
const Obj& findMax(const vector<Obj>& arr) {
    return findMax(arr, less<Obj>());
}

class CaseSensitiveCompare {
    public:
        bool operator() (const string& lhs, const string& rhs) const {
            return strcmp(lhs.c_str(), rhs.c_str()) < 0;
        }
};

TEST_CASE("Function template test", "[template]") {
    vector<int> squares(100);

    for (size_t i = 0; i < squares.size(); i++) {
        squares[i] = i*i;
    }

    REQUIRE(findMax(squares) == 9801);

    vector<string> strs(100);
    strs[0] = "a";
    strs[1] = "ab";
    strs[2] = "B";
    REQUIRE(findMax(strs, CaseSensitiveCompare()) == "ab");

    vector<double> doubles(100);
    REQUIRE(findMax(doubles) == 0);
}


// Class template
template <typename Object>
class MemoryCell {
    public:
        explicit MemoryCell(const Object& initValue = Object()) : storedValue(initValue) {}
        const Object& read() const {
            return storedValue;
        }
        void write(const Object& x) {
            storedValue = x;
        }
    private:
        Object storedValue;
};

TEST_CASE("Class template test", "[template]") {
    MemoryCell<int> m1(0);
    MemoryCell<string> m2("hi");

    REQUIRE(m1.read() == 0);
    REQUIRE(m2.read() == "hi");

    m2.write("who");
    REQUIRE(m2.read() == "who");
}
