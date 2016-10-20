#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ix = 0, jx = numbers.size() - 1;
        vector<int> indices;

        while (ix < jx) {
            int sum = numbers[ix] + numbers[jx];
            if (sum == target) {
                indices.push_back(ix + 1);
                indices.push_back(jx + 1);
                break;
            } else if (sum > target) {
                --jx;
            } else if (sum < target) {
                ++ix;
            }
        }

        return indices;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> indices = s.twoSum(nums, 18);
    std::cout << indices[0] << ", " << indices[1] << std::endl;

    return 0;
}
