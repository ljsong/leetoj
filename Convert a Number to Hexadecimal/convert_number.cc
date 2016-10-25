#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string ret;
        char nums[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        if (num == 0) {
            return "0";
        }

        unsigned int opnum = num >= 0 ? num : static_cast<unsigned int>((1 << 32) - 1) + num + 1;
        while(opnum != 0) {
            int digit = 0;
            for(int ix = 0; ix < 4; ++ix) {
                if (opnum & 0x1) {
                    digit += 1 << ix;
                }
                opnum >>= 1;
            }
            ret.push_back(nums[digit]);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    Solution s;
    int n;

    std::cout << "Input a number: ";
    std::cin >> n;

    std::cout << s.toHex(n) << std::endl;
    return 0;
}
