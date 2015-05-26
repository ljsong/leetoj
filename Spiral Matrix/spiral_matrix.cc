#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> nums;

        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return nums;
        }

        int ix = 0, jx = 0;
        int row = matrix.size(), column = matrix[0].size();
        int lbrow = ix, lbcolumn = jx;            // lb means lower bound
        int steps = 0;
        bool flag = true;
        while(lbrow < row && lbcolumn < column && flag) {
            if(steps == 0) {
                flag = traversal(jx, column, matrix[ix], nums, 1);
                steps++;
            } else if(steps == 1) {
                vector<int> col_vec;
                get_column(matrix, --jx, col_vec);
                flag = traversal(++ix, row, col_vec, nums, 1);
                steps++;
            } else if(steps == 2) {
                flag = traversal(--jx, lbcolumn, matrix[--ix], nums, 0);
                steps++;
            } else if(steps == 3) {
                vector<int> col_vec;
                get_column(matrix, ++jx, col_vec);
                if(--ix > lbrow) {
                    flag = traversal(ix, lbrow + 1, col_vec, nums, 0);
                }
                steps++;
            } else {
                ix = ++lbrow;
                jx = ++lbcolumn;
                --row;
                --column;
                steps = 0;
            }
        }
        
        return nums;
    }

private:
    void get_column(vector<vector<int> >& matrix, int col_index, vector<int>& column) {
        int row_size = matrix.size();

        for(int kx = 0; kx < row_size; ++kx) {
            column.push_back(matrix[kx][col_index]);
        }
    }

    bool traversal(int& ix, int bound, vector<int>& partial, vector<int>& nums, int direction) {
        if(ix < bound && direction == 1) {
            while(ix < bound) {
                nums.push_back(partial[ix++]);
            }
            return true;
        } else if (ix >= bound && direction == 0) { 
            while(ix >= bound) {
                nums.push_back(partial[ix--]);
            }
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    int a[][3] = {{1, 2, 3},
                {4, 5, 6}};
//                  {9, 10, 11, 12},
//                  {13, 14, 15, 16}};
    vector<vector<int> > matrix;

    for(int ix = 0; ix < 2; ++ix) {
        matrix.push_back(vector<int>(&a[ix][0], &a[ix][0] + 3));
    }
    vector<int> nums = s.spiralOrder(matrix);
    
    vector<int>::iterator itr = nums.begin();
    for(; itr != nums.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    return 0;
}
