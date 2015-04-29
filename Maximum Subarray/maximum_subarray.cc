#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int this_sum = 0, max_sum = 0;
        int ix = 0;

        for(max_sum = nums[0]; ix < nums.size() &&  nums[ix] < 0; ++ix) {
            max_sum = max_sum > nums[ix] ? max_sum : nums[ix];
        }
        
        if(ix >= nums.size()) {
            return max_sum;
        }
             
        for(int ix = 0; ix < nums.size(); ++ix) {
            this_sum += nums[ix];

            if(this_sum > max_sum) {
                max_sum = this_sum;
            } else if(this_sum < 0) {
                this_sum = 0;
            }
        }

        return max_sum;
    }
};

int main() {
    Solution s;
    int array[] = {-2, -1, -3, -4, -1, -2, -1, -5, -4};
    vector<int> ivec(&array[0], &array[0] + 9);

    std::cout << s.maxSubArray(ivec) << std::endl;

    return 0;
}
