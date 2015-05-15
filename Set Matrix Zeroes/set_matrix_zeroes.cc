#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return ;
        }
        
    }

private:
    void setRow(vector<vector<int> >& matrix, int ridx) {
        int column = matrix[0].size();

        for(int ix = 0; ix < column; ++ix) {
            if(matrix[ridx][ix] != 0) {
                matrix[ridx][ix] = 0;
            } else {
                setColumn(matrix, ix);
            }
        }
    }

    void setColumn(vector<vector<int> >& matrix, int cidx) {
        int row = matrix.size();

        for(int ix = 0; ix < row; ++ix) {
            if(matrix[ix][cidx] != 0) {
                matrix[ix][cidx] = 0;
            } else {
                setRow(matrix, ix);;
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}
