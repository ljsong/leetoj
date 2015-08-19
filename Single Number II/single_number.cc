#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }

        int ones = 0, twos = 0, threes = 0;
        int x = 0;
        for(int ix = 0; ix < nums.size(); ++ix) {
            x = nums[ix];
            twos |= ones & x;
            ones ^= x;

            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};

int main() {
    Solution s;
    int array[] = {1, 2, 3, 4, 5, 2, 1, 4, 5, 4, 2, 1, 5};
    vector<int> nums(&array[0], &array[13]);
    std::cout << s.singleNumber(nums) << std::endl;

    return 0;
}
