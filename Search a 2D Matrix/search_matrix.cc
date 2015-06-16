#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        int column = (row > 0 ? matrix[0].size() : 0);

        if(row == 0 || column == 0) {
            return false;
        }

        int ix = 0, jx = column - 1;

        while(ix < row && jx >= 0) {
            if(matrix[ix][jx] > target) {
               --jx;
            } else if(matrix[ix][jx] < target) {
               ++ix;
            } else {
               return true;
            } 
        }

        return false;
    }
};

int main() {
    Solution s;
    int a[][4] = {{1, 3, 5, 7},
                  {10, 11, 16, 20},
                  {23, 30, 34, 50}};
    vector<vector<int> > matrix;
    for(int ix = 0; ix < 3; ++ix) {
        vector<int> ivec(&a[ix][0], &a[ix][4]);
        matrix.push_back(ivec);
    }

    std::cout << s.searchMatrix(matrix, 6) << std::endl;

    return 0;
}
