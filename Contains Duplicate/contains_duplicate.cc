#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containDuplicate(vector<int>& nums) {
        if(nums.size() == 0) {
            return false;
        }

        vector<int>::iterator b = nums.begin(), e = nums.end();
        sort(b, e);

        for(int ix = 0, jx = ix + 1; ix < nums.size() - 1; ++ix, ++jx) {
            if(nums[ix] == nums[jx]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    int a[] = {};
    vector<int> nums(&a[0], &a[0]);

    std::cout << s.containDuplicate(nums) << std::endl;

    return 0;
}
