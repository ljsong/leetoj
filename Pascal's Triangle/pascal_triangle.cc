#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > matrix;

        if(numRows <= 0) {
            return matrix;
        } else if(numRows == 1) {
            matrix.push_back(vector<int>(1, 1));
        } else {
            matrix.push_back(vector<int>(1, 1));
            matrix.push_back(vector<int>(2, 1));

            int ix = 2, jx = 1;
            while(ix < numRows) {
                vector<int> ivec;
                jx = 1;

                ivec.push_back(1);
                for(; jx < ix; ++jx) {
                   ivec.push_back(matrix[ix - 1][jx - 1] + matrix[ix - 1][jx]); 
                }
                ivec.push_back(1);
                matrix.push_back(ivec);
                ++ix;
            }
        }

        return matrix;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Please input a number: ";
    cin >> n;

    vector<vector<int> > matrix = s.generate(n);

    for(int ix = 0; ix < n; ++ix) {
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
