#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        bool negative = false;
        unsigned int exp = n;

        if(n < 0) {
            negative = true;
            exp = -n;
        }

        while(exp != 0) {
            if(exp & 1) {
                result *= x;
            }

            exp >>= 1;
            x *= x;
        }

        return negative ? 1 / result : result; 
    }
};

int main() {
    Solution s;
    std::cout << s.myPow(-1, -2147483648) << std::endl;

    return 0;
}
