#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        return comb(2 * n, n) / (n + 1);    
    }

private:
    long comb(int m, int n) {
        if(n > m) {
            return 0;
        }

        long *c = new long[m + 1];
        long last_co = 0, old_co = 0;

        for(int ix = 0; ix <= m; ++ix) {
            last_co = 0;
            for(int jx = 0; jx <= ix; ++jx) {
                if(ix == jx || jx == 0) {
                    last_co = c[jx] = 1;
                } else {
                    old_co = c[jx];
                    c[jx] = c[jx] + last_co;
                    last_co = old_co;
                } 
            }
        }
        long result = c[n];
        delete[] c;

        return result;
    }

};

int main() {
    Solution s;
    std::cout << s.numTrees(19) << std::endl;

    return 0;
}
