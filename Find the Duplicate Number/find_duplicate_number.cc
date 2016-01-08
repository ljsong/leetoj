#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int count = length(nums, mid);
            if (count <= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

private:
    int length(vector<int>& nums, int threshold) {
        int count = 0;

        for(int ix = 0; ix < nums.size(); ++ix) {
            if (nums[ix] <= threshold) {
                ++count;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    int a[] = {1, 2, 3, 5, 5, 5};
    vector<int> v(&a[0], &a[6]);
    std::cout << s.findDuplicate(v) << std::endl;

    return 0;
}
