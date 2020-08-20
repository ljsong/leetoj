#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) {
            return 0;
        }

        int msb = 31;
        uint32_t mask = 1 << msb;
        for (; !(mask & n); mask >>= 1, --msb) {}

        std::cout << "msb = " << msb << std::endl;
        int ret = 0;
        while(msb >= 0) {
            if (m <= mask - 1) {
                return ret;
            }

            ret += ((1 << msb) & n);
            --msb;
            mask += ((1 << msb) & n);
        }

        return ret;
    }
};

int main() {
    Solution s;

    std::cout << s.rangeBitwiseAnd(3, 3) << std::endl;
    return 0;
}
