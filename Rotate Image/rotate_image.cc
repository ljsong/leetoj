#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();

        if(n == 0 || n == 1) {
            return ;
        }

        int half = (n >> 1);
        int count = 0;
        while(count <= half) {  // start from the diagnal, (0,0) ->(1,1)->(2,2) 
            int bound = n - 1 - count;    // an element transpose its place will cause a loop such as: 
            for(int ix = count; ix < bound; ++ix) {   // (0,0) -> (0,3) -> (3,3) -> (3,0) -> (0,0)(given n = 4)
                int row = count, col = ix, kx;  // column changed according to count
                int val = matrix[row][col];
                for(int jx = 0; jx < 4; ++jx) {  // transposition will affected four elements that build a loop
                   int tmp = matrix[col][n - 1 - row]; 
                   matrix[col][n - 1 -row] = val;
                   val = tmp;
                   kx = row;
                   row = col;
                   col = n - 1 - kx;
                }
            }
            ++count;
        }
    }
};

int main() {
    Solution s;
    int matrix[][3] = {{1, 2, 3},
                 {5, 6, 7},
                 {9, 10, 11}};
    vector<vector<int> > grid;
    for(int ix = 0; ix < 3; ++ix) {
        vector<int> ivec(&matrix[ix][0], &matrix[ix][4]);
        grid.push_back(ivec);
    }
    s.rotate(grid);

    for(int ix = 0; ix < 3; ++ix) {
        for(int jx = 0; jx < 3; ++jx) {
            std::cout << grid[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
