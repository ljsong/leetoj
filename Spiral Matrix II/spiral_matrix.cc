#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> vec(n, -1);
        vector<vector<int> > matrix(n, vec);

        if (n <= 0) {
            return matrix;
        }

        start = 0, end = n; // exclude the end
        int cnt = 1;

        for(int ix = 0; ix <= n / 2; ++ix) {
            row = column = start;
            step_row = STAY, step_column = RIGHT;
            while(step_row != STAY || step_column != STAY) {
                if (matrix[row][column] == -1) {
                    matrix[row][column] = cnt;
                    ++cnt;
                }
                row += step_row;
                column += step_column;
                adjustDirection();
            }
        }

        return matrix;
    }

private:
    void adjustDirection() {
        if (row >= end) {
            step_row = STAY;
            step_column = LEFT;
            --row;
        }
        else if (row < start) {
            step_row = STAY;
            step_column = STAY;
            start++;
            end--;
            return ;
        }

        if (column >= end) {
            step_column = STAY;
            step_row = DOWN;
            --column;
        }
        else if (column < start) {
            ++column;
            step_column = STAY;
            step_row = UP;
        }
    }

private:
    int step_row, step_column;  // length of each step
    int start, end; // the bound of each circle
    int row, column;    // the index of row and column
    const static int LEFT = -1;
    const static int RIGHT = 1;
    const static int UP = -1;
    const static int DOWN = 1;
    const static int STAY = 0;
};

int main() {
    Solution s;
    int num;

    std::cout << "Input a number: ";
    std::cin >> num;
    vector<vector<int> > matrix = s.generateMatrix(num);
    for(int ix = 0; ix < matrix.size(); ++ix) {
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
