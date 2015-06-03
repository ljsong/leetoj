#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ix = 0, jx = 1, offset = 0;
        int count = nums.size(), total = 0;
        
        while(ix < count - 1) {
            if(nums[ix] != nums[jx]) {
                ix = jx;
                jx = ix + 1;
                total += offset;
                nums[ix - total] = nums[ix];
                offset = 0;         //reset the offset in case of duplicate
            } else {
                offset = jx - ix;
                ++jx;
                if(jx >= count) {
                    total += offset;
                    break;
                }
            }
        }

        return count - total;
    }
};

int main() {
    Solution s;
    int a[] = {1, 1, 2, 3, 3};
    vector<int> ivec(&a[0], &a[0] + 5);
    int count = s.removeDuplicates(ivec);
    for(int ix = 0; ix < count; ++ix) {
        std::cout << ivec[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
