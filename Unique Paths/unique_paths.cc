#include <iostream>
using namespace std;

class Solution {
public:
    //F(m, n) = F(m - 1, n) + F(m. n - 1)
    int uniquePaths(int m, int n) {
        int **matrix = new int*[m + 1];
        for(int ix = 0; ix <= m; ++ix) {
            matrix[ix] = new int[n + 1];
        }

        for(int ix = 0; ix <= m; ++ix) {
            matrix[ix][0] = 0;
            matrix[ix][1] = 1;//n row, 1 columns has only one kind of path 
        }

        for(int jx = 0; jx <= n; ++jx) {
            matrix[0][jx] = 0;
            matrix[1][jx] = 1;//1 row, n columns also has only one kind of path
        }

        for(int ix = 1; ix <= m; ++ix) {
            for(int jx = 1; jx <= n; ++jx) {
                matrix[ix][jx] = matrix[ix - 1][jx] + matrix[ix][jx - 1];
            }
        }

        return matrix[m][n];
    }
};

int main() {
    Solution s;
    int m, n;
    std::cin >> m >> n;

    std::cout << s.uniquePaths(m, n) << std::endl;

    return 0;
}
