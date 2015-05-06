#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = low;

        while(nums[low] > nums[high]) {
            if(high - low == 1) {
                mid = high;
                break;
            }

            mid = ((high - low) >> 1) + low; 
            if(nums[mid] >= nums[low]) {
                low = mid;
            } else if(nums[mid] <= nums[high]) {
                high = mid;
            }
        }

        return nums[mid];
    }
};

int main() {
    Solution s;
    int a[] = {2};
    vector<int> ivec(&a[0], &a[0] + 1);
    std::cout << s.findMin(ivec) << std::endl;

    return 0;
}
