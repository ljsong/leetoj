#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos = 31;
        uint32_t mask = 1 << pos, output = 0;
        while(pos >= 0) {
            uint32_t bit = (!!(n & mask) << (31 - pos));
            output |= bit;
            mask >>= 1;
            --pos;
        }

        return output;
    }
};

int main()
{
    Solution s;
    uint32_t n;
    std::cin >> n;
    std::cout << s.reverseBits(n) << std::endl;
    return 0;
}
