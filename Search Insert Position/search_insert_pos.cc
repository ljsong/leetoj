#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size(), mid = 0;

        while(low < high) {
            mid = ((high - low) >> 1) + low;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else if(nums[mid] > target) {
                high = mid;
            }
        }
        
        return low;    //low pointer indicate the inserting position
    }
};

int main() {
    Solution s;
    int a[] = {1, 3, 5, 6};
    vector<int> ivec(&a[0], &a[0] + 4);

    std::cout << s.searchInsert(ivec, 2) << std::endl;

    return 0;
}
