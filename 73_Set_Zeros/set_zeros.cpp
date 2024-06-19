#include <vector>
#include <unordered_set>
#include <iostream>

/**
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 */

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }

        std::unordered_set<int> rows, cols;
        for (int ix = 0; ix < matrix.size(); ++ix) {
            for (int jx = 0; jx < matrix[0].size(); ++jx) {
                if (matrix[ix][jx] == 0) {
                    rows.insert(ix);
                    cols.insert(jx);
                }
            }
        }

        for (const auto& row : rows) {
            for (int jx = 0; jx < matrix[0].size(); ++jx) {
                matrix[row][jx] = 0;
            }
        }

        for (const auto& col : cols) {
            for (int ix = 0; ix < matrix.size(); ++ix) {
                matrix[ix][col] = 0;
            }
        }
    }

    // O(1) complexity of space by referencing LeetCode
    void setZero(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        bool first_row_has_zero = false, first_col_has_zero = false;
        for (int ix = 0; ix < matrix[0].size(); ++ix) {
            if (matrix[0][ix] == 0) {
                first_row_has_zero = true;
                break;
            }
        }

        for (int ix = 0; ix < matrix.size(); ++ix) {
            if (matrix[ix][0] == 0) {
                first_col_has_zero = true;
                break;
            }
        }

        for (int ix = 1; ix < matrix.size(); ++ix) {
            for (int jx = 1; jx < matrix[0].size(); ++jx) {
                if (matrix[ix][jx] == 0) {
                    matrix[ix][0] = 0;
                    matrix[0][jx] = 0;
                }
            }
        }

        for (int ix = 1; ix < matrix.size(); ++ix) {
            for (int jx = 1; jx < matrix[0].size(); ++jx) {
                if (!matrix[ix][0] || !matrix[0][jx]) {
                    matrix[ix][jx] = 0;
                }
            }
        }

        if (first_row_has_zero) {
            for (int ix = 0; ix < matrix[0].size(); ++ix) {
                matrix[0][ix] = 0;
            }
        }

        if (first_col_has_zero) {
            for (int ix = 0; ix < matrix.size(); ++ix) {
                matrix[ix][0] = 0;
            }
        }
    }
};

int main() {
    /**
     * 0 1 2 0
     * 3 4 5 2
     * 1 3 1 5
     */
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZero(matrix);

    for (int ix = 0; ix < matrix.size(); ++ix) {
        for (int jx = 0; jx < matrix[0].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}