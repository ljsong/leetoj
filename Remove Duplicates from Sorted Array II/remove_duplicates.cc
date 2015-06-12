#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ix = 0, jx = 1, offset = 0;
        int count = nums.size(), total = 0;
        bool deleted = false;

        while(ix < count - 1 && jx < count) {
            if(nums[ix] != nums[jx]) {
                ix = jx;
                total += offset;
                nums[ix - total] = nums[ix];
                offset = 0;
                deleted = false;
            } else if(deleted) {
                offset = jx - ix - 1;
            } else {
                deleted = true;
                nums[jx - total] = nums[jx];
            }
            ++jx;
        }

        total += offset; 
        return count - total; 
    }
};

int main() {
    Solution s;
    int a[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(&a[0], &a[0] + 6);

    int size = s.removeDuplicates(nums);
    for(int ix = 0; ix < size; ++ix) {
        std::cout << nums[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
