#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include "catch.hpp"

using namespace std;

template <typename Obj>
class matrix {
    public:
        matrix (int rows, int cols) : m_matrix(rows) {
            for (size_t i = 0; i < rows; i++) {
                m_matrix[i].resize(cols);
            }
        }

        const vector<Obj>& operator[] (int row) const {
            return m_matrix[row];
        }

        vector<Obj>& operator[] (int row) {
            return m_matrix[row];
        }

        int numrows() const {
            return m_matrix.size();
        }

        int numcols() const {
            return numrows() ? m_matrix[0].size() : 0;
        }

    private:
        vector< vector<Obj> > m_matrix;
};

TEST_CASE("Matrix create", "[matrix]") {
    matrix<int> m(10, 10);
    REQUIRE(m.numrows() == 10);
    REQUIRE(m.numcols() == 10);
}
