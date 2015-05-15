#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0) {
            return 0;
        }

        int **matrix = new int*[m];
        int ix = 0, jx = 0;
        for(; ix < m; ++ix) {
            matrix[ix] = new int[n];
        }

        matrix[0][0] = grid[0][0];
        for(ix = 1; ix < n; ++ix) {
            matrix[0][ix] = matrix[0][ix - 1] + grid[0][ix];
        }
        for(ix = 1; ix < m; ++ix) {
            matrix[ix][0] = matrix[ix - 1][0] + grid[ix][0];
        }

        for(ix = 1; ix < m; ++ix) {
            for(jx = 1; jx < n; ++jx) {
                int val = matrix[ix][jx - 1] > matrix[ix - 1][jx] ? matrix[ix - 1][jx] : matrix[ix][jx - 1];
                matrix[ix][jx] = val + grid[ix][jx];
            }
        }

        return matrix[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    int matrix[][3] = {{1, 2, 3},
                       {3, 0, 2},
                       {1, 1, 4}};
    vector<vector<int> > grid;
    for(int ix = 0; ix < 3; ++ix) {
        vector<int> ivec(&matrix[ix][0], &matrix[ix][3]);
        grid.push_back(ivec);
    }

    std::cout << s.minPathSum(grid) << std::endl;

    return 0;
}
