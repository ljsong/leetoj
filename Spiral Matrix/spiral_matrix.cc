/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *   [ 1, 2, 3 ],
 *   [ 8, 9, 4 ],
 *   [ 7, 6, 5 ]
 * ]
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int direction_r = 0, direction_c = 1;
        int row = 0, col = 0;
        int cnt = 1, total = n * n;
        vector<int> vec(n, -1);
        vector<vector<int> > matrix(n, vec);
       
        while (cnt <= total) {
            matrix[row][column] = cnt;
            ++cnt;
            row += direction_r;
            column += direction_c;

            if (row >= n) {
                direction_c = -1;
                --row;
            } else if (row < 0) {
                direction_c = 1;
                ++row;
            }

            if (column >= n) {
                direction_r = 1;
                --column;
            } else if (column < 0) {
                direction_r = -1;
                ++column;
            }
    }
};

int main() {
    Solution s;

    return 0;
}
