#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        int n = nums.size();
        long sum = 0;
        long original = (n & 1 ? (n + 1 >> 1) * n : (n >> 1) * (n + 1)); 
        for(int ix = 0; ix < n; ++ix) {
            sum += nums[ix];
        }

        return original - sum;
    }
};

int main() {
    Solution s;
    int array[] = {1, 3, 5, 2, 0};
    vector<int> nums(&array[0], &array[0] + 5);
    std::cout << s.missingNumber(nums) << std::endl;

    return 0;
}
