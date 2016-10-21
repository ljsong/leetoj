#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string rets;
        
        if (s.empty()) {
            return rets;
        }

        int counts[26] = {0}, len = s.length();
        int nums[10] = {0};

        for(int ix = 0; ix < len; ++ix) {
            ++counts[s[ix] - 'a'];
        }

        nums[0] = counts['z' - 'a'];
        nums[2] = counts['w' - 'a'];
        nums[4] = counts['u' - 'a'];
        nums[6] = counts['x' - 'a'];
        nums[8] = counts['g' - 'a'];
        nums[1] = counts['o' - 'a'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['t' - 'a'] - nums[2] - nums[8];
        nums[5] = counts['f' - 'a'] - nums[4];
        nums[7] = counts['s' - 'a'] - nums[6];
        nums[9] = counts['i' - 'a'] - nums[5] - nums[6] - nums[8];

        for (int ix = 0; ix < 10; ++ix) {
            rets += string(nums[ix], '0' + ix);
        }

        return rets;

    }
};

int main() {
    Solution s;
    string str;

    std::cout << "Please input a string: ";
    std::cin >> str;

    std::cout << s.originalDigits(str) << std::endl;
    return 0;
}
