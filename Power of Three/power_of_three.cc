#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }

        double result = log(n) / log(3);
        double round_result = (int)(result + 0.5);
        return (abs(round_result - result) < 10e-8);
    }
};

int main() {
    Solution s;
    std::cout << s.isPowerOfThree(129140162) << std::endl;

    return 0;
}
