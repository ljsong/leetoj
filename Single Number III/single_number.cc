#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;

        if (nums.size() <= 2) {
            return nums;
        }

        int xor_result = 0;
        for(int ix = 0; ix < nums.size(); ++ix) {
            xor_result ^= nums[ix];
        }

        int bits = 0;
        while(!(xor_result & 1)) {
            xor_result >>= 1;
            ++bits;
        }

        int check_point = 1 << bits;
        int first_number = 0, second_number = 0;
        for(int ix = 0; ix < nums.size(); ++ix) {
            if (nums[ix] & check_point) {
                first_number ^= nums[ix];
            } else {
                second_number ^= nums[ix];
            }
        }

        result.push_back(first_number);
        result.push_back(second_number);

        return result;
    }
};

int main() {
    Solution s;
    int array[] = {1, 3, 5, 2, 5, 4, 3, 1};
    vector<int> nums(&array[0], &array[8]);
    vector<int> result = s.singleNumber(nums);

    for(int ix = 0; ix < result.size(); ++ix) {
        std::cout << result[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
