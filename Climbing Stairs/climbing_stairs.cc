#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 2, fn= 0;

        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return f1;
        } else if(n == 2) {
            return f2;
        } else {
            int ix = 3;
            while(ix <= n) {
                fn = f1 + f2;
                f1 = f2;
                f2 = fn;
                ++ix;
            }
        }
        
        return fn;
    }
};

int main() {
    Solution s;
    int n;

    std::cin >> n;
    std::cout << "Total: " << s.climbStairs(n) << std::endl;

    return 0;
}
