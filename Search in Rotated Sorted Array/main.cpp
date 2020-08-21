#include <iostream>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = ((high - low) >> 1) + low;
            if (target == nums[mid]) {
                return mid;
            }

            if (nums[mid] >= nums[low]) {
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> vec = {1};
    Solution s;
    std::cout << s.search(vec, 2) << std::endl;
    return 0;
}
